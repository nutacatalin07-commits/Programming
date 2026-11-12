#ifndef BMP_IO_RGB_H
#define BMP_IO_RGB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define BMP_GET32(p) ((uint32_t)(p)[0] | (uint32_t)(p)[1]<<8 | (uint32_t)(p)[2]<<16 | (uint32_t)(p)[3]<<24)
#define BMP_PUT32(p,v) do { uint32_t bmp_v_ = (uint32_t)(v); for(int bmp_k_=0; bmp_k_<4; ++bmp_k_) (p)[bmp_k_] = (unsigned char)(bmp_v_ >> (8*bmp_k_)); } while(0)

static inline unsigned char ***bmp_read(const char *path, int *N, int *M)
{
    if (!N || !M || N == M) return NULL;
    *N = *M = 0; if (!path) return NULL;
    FILE *f = fopen(path, "rb"); if (!f) return NULL;
    unsigned char h[54], *buf=NULL, ***img=NULL; int nr=0, nc=0;
    if (fread(h, 1, 54, f) != 54 || h[0]!='B' || h[1]!='M') goto fail;
    uint32_t off=BMP_GET32(h+10), dib=BMP_GET32(h+14), w=BMP_GET32(h+18), sh=BMP_GET32(h+22);
    int top = (int)(sh >> 31), b = h[28]/8; uint32_t n = top ? (uint32_t)(0u-sh) : sh;
    if ((dib!=40 && dib!=52 && dib!=56 && dib!=108 && dib!=124) || (uint64_t)off<14ull+dib ||
        h[26]!=1 || h[27] || (h[28]!=24 && h[28]!=32) || h[29] || BMP_GET32(h+30) ||
        !w || w>INT32_MAX || w>INT_MAX || !n || n>INT32_MAX || n>INT_MAX) goto fail;
    uint64_t stride = ((uint64_t)w*b+3)/4*4;
    if (stride>SIZE_MAX || (uint64_t)n*sizeof(*img)>SIZE_MAX || (uint64_t)w*sizeof(**img)>SIZE_MAX) goto fail;
    if (fseek(f, 0, SEEK_END)) goto fail;
    long len = ftell(f);
    if (len<0 || (uint64_t)len<(uint64_t)off+stride*n || fseek(f, (long)off, SEEK_SET)) goto fail;
    img=malloc((size_t)n*sizeof(*img)); buf=malloc((size_t)stride); if (!img || !buf) goto fail;
    for (uint32_t y=0; y<n; ++y) {
        img[y]=malloc((size_t)w*sizeof(**img)); if (!img[y]) goto fail; ++nr; nc=0;
        for (uint32_t x=0; x<w; ++x) { img[y][x]=malloc(3); if (!img[y][x]) goto fail; ++nc; }
    }
    for (uint32_t y=0; y<n; ++y) {
        if (fread(buf, 1, (size_t)stride, f)!=(size_t)stride) goto fail;
        for (size_t x=0; x<w; ++x)
            for (int k=0; k<3; ++k) img[top?y:n-1-y][x][k]=buf[b*x+2-k];
    }
    free(buf); fclose(f); *N=(int)n; *M=(int)w; return img;
fail:
    if (img) { for (int y=0; y<nr; ++y) { for (uint32_t x=0; x<(y==nr-1?(uint32_t)nc:w); ++x) free(img[y][x]); free(img[y]); } free(img); }
    free(buf); fclose(f); return NULL;
}

static inline int bmp_write(const char *path, unsigned char ***img, int N, int M)
{
    if (!path || !img || N<=0 || M<=0) return 0;
    if ((uint64_t)N>INT32_MAX || (uint64_t)M>INT32_MAX) return 0;
    uint64_t stride=((uint64_t)M*3+3)/4*4, bytes=stride*(uint64_t)N;
    if (stride>SIZE_MAX || bytes>UINT32_MAX-54u) return 0;
    for (int y=0; y<N; ++y) { if (!img[y]) return 0; for (int x=0; x<M; ++x) if (!img[y][x]) return 0; }
    unsigned char h[54]={0}, *buf=calloc(1,(size_t)stride); if (!buf) return 0;
    h[0]='B'; h[1]='M'; h[26]=1; h[28]=24;
    BMP_PUT32(h+2,54+bytes); BMP_PUT32(h+10,54); BMP_PUT32(h+14,40);
    BMP_PUT32(h+18,M); BMP_PUT32(h+22,N); BMP_PUT32(h+34,bytes);
    FILE *f=fopen(path,"wb"); if (!f) { free(buf); return 0; }
    int ok=fwrite(h,1,54,f)==54;
    for (int y=N; ok && y-->0;) {
        for (size_t x=0; x<(size_t)M; ++x)
            for (int k=0; k<3; ++k) buf[3*x+2-k]=img[y][x][k];
        ok=fwrite(buf,1,(size_t)stride,f)==(size_t)stride;
    }
    if (fclose(f)!=0) ok=0;
    free(buf); return ok;
}
#undef BMP_GET32
#undef BMP_PUT32
#endif

// ==========================================
// MODULUL 3: Desenare dreptunghi roșu cu grosimea de k pixeli
// ==========================================
void deseneaza_dreptunghi(unsigned char ***img, int N, int M, int left, int right, int top, int bottom, int k) {
    if (left < 0) left = 0;
    if (right >= M) right = M - 1;
    if (top < 0) top = 0;
    if (bottom >= N) bottom = N - 1;

    for (int y = top; y <= bottom; ++y) {
        for (int x = left; x <= right; ++x) {
            int e_pe_chenar_orizontal = (y < top + k) || (y > bottom - k);
            int e_pe_chenar_vertical = (x < left + k) || (x > right - k);

            if (e_pe_chenar_orizontal || e_pe_chenar_vertical) {
                img[y][x][0] = 255; // Roșu
                img[y][x][1] = 0;   // Verde
                img[y][x][2] = 0;   // Albastru
            }
        }
    }
}

// ==========================================
// MODULUL 4: Crop imagine după coordonate
// ==========================================
unsigned char ***crop_image(unsigned char ***img, int N, int M, int left, int right, int top, int bottom, int *new_N, int *new_M) {
    if (left < 0) left = 0;
    if (right >= M) right = M - 1;
    if (top < 0) top = 0;
    if (bottom >= N) bottom = N - 1;

    if (left > right || top > bottom) {
        *new_N = 0; *new_M = 0;
        return NULL;
    }

    int n_nou = bottom - top + 1;
    int m_nou = right - left + 1;

    unsigned char ***img_nou = malloc((size_t)n_nou * sizeof(**img_nou));
    if (!img_nou) return NULL;

    for (int y = 0; y < n_nou; ++y) {
        img_nou[y] = malloc((size_t)m_nou * sizeof(**img_nou));
        if (!img_nou[y]) {
            for (int i = 0; i < y; ++i) {
                for (int x = 0; x < m_nou; ++x) free(img_nou[i][x]);
                free(img_nou[i]);
            }
            free(img_nou);
            return NULL;
        }
        for (int x = 0; x < m_nou; ++x) {
            img_nou[y][x] = malloc(3);
            if (!img_nou[y][x]) {
                for (int j = 0; j <= x; ++j) free(img_nou[y][j]);
                for (int i = 0; i < y; ++i) {
                    for (int xx = 0; xx < m_nou; ++xx) free(img_nou[i][xx]);
                    free(img_nou[i]);
                }
                free(img_nou);
                return NULL;
            }
        }
    }

    for (int y = 0; y < n_nou; ++y) {
        for (int x = 0; x < m_nou; ++x) {
            for (int k = 0; k < 3; ++k) {
                img_nou[y][x][k] = img[top + y][left + x][k];
            }
        }
    }

    *new_N = n_nou;
    *new_M = m_nou;
    return img_nou;
}

// ==========================================
// MODULUL 5: Conversie în tonuri de gri (Grayscale)
// ==========================================
void converteste_grayscale(unsigned char ***img, int N, int M) {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            unsigned char mediu = (img[y][x][0] + img[y][x][1] + img[y][x][2]) / 3;
            img[y][x][0] = mediu;
            img[y][x][1] = mediu;
            img[y][x][2] = mediu;
        }
    }
}

// ==========================================
// MODULUL 6: Imagine pătrată pentru Instagram (cu padding / bonus culori capete)
// ==========================================
// ==========================================
// MODULUL 6: Imagine pătrată (fundal blurat din aceeași imagine)
// ==========================================
static void elibereaza_imagine(unsigned char ***img, int N, int M) {
    if (!img) return;
    for (int y = 0; y < N; ++y) {
        if (img[y]) {
            for (int x = 0; x < M; ++x) free(img[y][x]);
            free(img[y]);
        }
    }
    free(img);
}

// Blur box pe o singură linie (marginile se extind cu primul/ultimul pixel).
// step = distanța în memorie dintre două elemente consecutive ale liniei.
static void blur_linie(const unsigned char *src, unsigned char *dst, int len, size_t step, int r) {
    int win = 2 * r + 1;
    long sum = 0;
    for (int i = -r; i <= r; ++i) {
        int j = i < 0 ? 0 : (i >= len ? len - 1 : i);
        sum += src[(size_t)j * step];
    }
    for (int i = 0; i < len; ++i) {
        dst[(size_t)i * step] = (unsigned char)(sum / win);
        int add = i + r + 1; if (add >= len) add = len - 1;
        int sub = i - r;     if (sub < 0)    sub = 0;
        sum += src[(size_t)add * step] - src[(size_t)sub * step];
    }
}

// Blur pe un buffer plat de W x H pixeli RGB (orizontal, apoi vertical)
static void blur_buffer(unsigned char *buf, unsigned char *tmp, int W, int H, int r) {
    for (int y = 0; y < H; ++y)
        for (int c = 0; c < 3; ++c)
            blur_linie(buf + (size_t)y * W * 3 + c, tmp + (size_t)y * W * 3 + c, W, 3, r);
    for (int x = 0; x < W; ++x)
        for (int c = 0; c < 3; ++c)
            blur_linie(tmp + (size_t)x * 3 + c, buf + (size_t)x * 3 + c, H, (size_t)W * 3, r);
}

unsigned char ***fa_imaginea_patrata(unsigned char ***img, int N, int M, int *new_N, int *new_M) {
    int latura = (N > M) ? N : M;
    int pad_y = (latura - N) / 2;
    int pad_x = (latura - M) / 2;
    int mic   = (N < M) ? N : M;

    // 1. Alocare imagine nouă (calloc ca să putem elibera sigur la eroare)
    unsigned char ***img_nou = calloc((size_t)latura, sizeof(*img_nou));
    if (!img_nou) return NULL;
    for (int y = 0; y < latura; ++y) {
        img_nou[y] = calloc((size_t)latura, sizeof(**img_nou));
        if (!img_nou[y]) { elibereaza_imagine(img_nou, latura, latura); return NULL; }
        for (int x = 0; x < latura; ++x) {
            img_nou[y][x] = malloc(3);
            if (!img_nou[y][x]) { elibereaza_imagine(img_nou, latura, latura); return NULL; }
        }
    }

    // 2. Fundal: pătratul central al imaginii, mărit la latura x latura
    unsigned char *buf = malloc((size_t)latura * latura * 3);
    unsigned char *tmp = malloc((size_t)latura * latura * 3);
    if (!buf || !tmp) { free(buf); free(tmp); elibereaza_imagine(img_nou, latura, latura); return NULL; }

    int off_y = (N - mic) / 2, off_x = (M - mic) / 2;
    for (int y = 0; y < latura; ++y) {
        int sy = off_y + (int)((long long)y * mic / latura);
        for (int x = 0; x < latura; ++x) {
            int sx = off_x + (int)((long long)x * mic / latura);
            for (int k = 0; k < 3; ++k)
                buf[((size_t)y * latura + x) * 3 + k] = img[sy][sx][k];
        }
    }

    // 3. Blur puternic (3 treceri ≈ blur gaussian) + întunecare
    int r = latura / 25; if (r < 2) r = 2;
    for (int i = 0; i < 3; ++i) blur_buffer(buf, tmp, latura, latura, r);

    for (int y = 0; y < latura; ++y)
        for (int x = 0; x < latura; ++x)
            for (int k = 0; k < 3; ++k)
                img_nou[y][x][k] = (unsigned char)(buf[((size_t)y * latura + x) * 3 + k] * 70 / 100);
    free(buf); free(tmp);

    // 4. Imaginea originală, nemodificată, în centru
    for (int y = 0; y < N; ++y)
        for (int x = 0; x < M; ++x)
            for (int k = 0; k < 3; ++k)
                img_nou[y + pad_y][x + pad_x][k] = img[y][x][k];

    *new_N = latura;
    *new_M = latura;
    return img_nou;
}
// ==========================================
// FUNCȚIA MAIN (Meniu pentru testarea opțiunilor)
// ==========================================
int main() {
    int N = 0, M = 0;
    const char *input_path = "input.bmp";
    const char *output_path = "output.bmp";

    // 1. Citire imagine inițială
    unsigned char ***img = bmp_read(input_path, &N, &M);
    if (!img) {
        fprintf(stderr, "Erore la citirea imaginii: %s\n", input_path);
        return 1;
    }
    printf("Imagine citita cu succes: L=%d x H=%d\n", M, N);

    // Alege opțiunea dorită:
    // 1 = Copiere simplă
    // 2 = Dreptunghi roșu
    // 3 = Crop
    // 4 = Grayscale (Alb-negru)
    // 5 = Pătrată pentru Instagram
    int optiune = 5;

    if (optiune == 1) {
        if (bmp_write(output_path, img, N, M)) {
            printf("Salvat cu succes in %s\n", output_path);
        }
    } 
    else if (optiune == 2) {
        int left = 50, right = 200, top = 50, bottom = 200, k = 3;
        deseneaza_dreptunghi(img, N, M, left, right, top, bottom, k);
        if (bmp_write(output_path, img, N, M)) {
            printf("Dreptunghi desenat si salvat in %s\n", output_path);
        }
    } 
    else if (optiune == 3) {
        int left = 50, right = 200, top = 50, bottom = 200;
        int new_N = 0, new_M = 0;
        
        unsigned char ***img_crop = crop_image(img, N, M, left, right, top, bottom, &new_N, &new_M);
        if (img_crop) {
            // Scriem direct noua imagine cropată
            if (bmp_write(output_path, img_crop, new_N, new_M)) {
                printf("Imagine cropata (%d x %d) salvata in %s\n", new_M, new_N, output_path);
            }
            // Eliberăm memoria pentru imaginea cropată
            for (int y = 0; y < new_N; ++y) {
                for (int x = 0; x < new_M; ++x) free(img_crop[y][x]);
                free(img_crop[y]);
            }
            free(img_crop);
        } else {
            fprintf(stderr, "Erore la crop (coordonate invalide).\n");
        }
    } 
    else if (optiune == 4) {
        converteste_grayscale(img, N, M);
        if (bmp_write(output_path, img, N, M)) {
            printf("Conversie grayscale salvata in %s\n", output_path);
        }
    } 
    else if (optiune == 5) {
        int new_N = 0, new_M = 0;
        unsigned char ***img_sq = fa_imaginea_patrata(img, N, M, &new_N, &new_M);
        if (img_sq) {
            // Scriem direct noua imagine pătrată
            if (bmp_write(output_path, img_sq, new_N, new_M)) {
                printf("Imagine patrata (%d x %d) salvata in %s\n", new_M, new_N, output_path);
            }
            // Eliberăm memoria pentru imaginea pătrată
            for (int y = 0; y < new_N; ++y) {
                for (int x = 0; x < new_M; ++x) free(img_sq[y][x]);
                free(img_sq[y]);
            }
            free(img_sq);
        } else {
            fprintf(stderr, "Erore la transformarea in imagine patrata.\n");
        }
    }

    // Eliberarea memoriei pentru imaginea originală citită la început
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            free(img[y][x]);
        }
        free(img[y]);
    }
    free(img);

    return 0;
}