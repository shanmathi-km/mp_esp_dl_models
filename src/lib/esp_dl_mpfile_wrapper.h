/*
 * ESP-DL MicroPython File Wrapper
 * 
 * This header provides forward declarations for mpfile functions
 * that can be used by esp-dl components during compilation.
 * The actual implementation is provided later during linking
 * when the usermod is built.
 */

#ifndef __ESP_DL_MPFILE_WRAPPER_H__
#define __ESP_DL_MPFILE_WRAPPER_H__

#include <sys/types.h>  // for off_t
#include <stddef.h>     // for size_t
#include <stdbool.h>    // for bool

#ifdef __cplusplus
extern "C" {
#endif

// Opaque pointer type for esp-dl file operations
typedef void esp_dl_mp_file_t;

// Opaque pointer type for esp-dl print operations
typedef void esp_dl_mp_print_t;

// File operation constants
#define ESP_DL_MP_SEEK_SET 0
#define ESP_DL_MP_SEEK_CUR 1
#define ESP_DL_MP_SEEK_END 2
// Basic compatibility definitions for ESP-DL compilation
#ifndef SEEK_SET
#define SEEK_SET 0
#endif

#ifndef SEEK_CUR
#define SEEK_CUR 1
#endif

#ifndef SEEK_END
#define SEEK_END 2
#endif

// Function declarations for esp-dl
bool esp_dl_mp_isfile(const char *path);
esp_dl_mp_file_t *esp_dl_mp_open(const char *filename, const char *mode);
int esp_dl_mp_readinto(esp_dl_mp_file_t *file, void *buf, size_t num_bytes);
int esp_dl_mp_write(esp_dl_mp_file_t *file, const void *buf, size_t num_bytes);
off_t esp_dl_mp_seek(esp_dl_mp_file_t *file, off_t offset, int whence);
off_t esp_dl_mp_tell(esp_dl_mp_file_t *file);
void esp_dl_mp_close(esp_dl_mp_file_t *file);

// Print operation functions for esp-dl
extern esp_dl_mp_print_t *esp_dl_mp_plat_print;
int esp_dl_mp_printf(esp_dl_mp_print_t *print, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif // __ESP_DL_MPFILE_WRAPPER_H__
