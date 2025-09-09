/*
 * ESP-DL MicroPython File Wrapper Implementation
 * 
 * This file provides the actual implementation of the wrapper functions
 * that bridge esp-dl components to the MicroPython file system.
 * These functions are built with the usermod and linked at the end.
 */

#include "esp_dl_mpfile_wrapper.h"
#include "mpfile.h"
#include <stdarg.h>

// External MicroPython declarations
extern const mp_print_t mp_plat_print;
extern int mp_printf(const mp_print_t *print, const char *fmt, ...);
extern int mp_vprintf(const mp_print_t *print, const char *fmt, va_list args);

// Export the platform print structure for esp-dl
esp_dl_mp_print_t *esp_dl_mp_plat_print = (esp_dl_mp_print_t *)&mp_plat_print;

bool esp_dl_mp_isfile(const char *path) {
    return mp_isfile(path);
}

esp_dl_mp_file_t *esp_dl_mp_open(const char *filename, const char *mode) {
    return (esp_dl_mp_file_t *)mp_open(filename, mode);
}

int esp_dl_mp_readinto(esp_dl_mp_file_t *file, void *buf, size_t num_bytes) {
    return (int)mp_readinto((mp_file_t *)file, buf, num_bytes);
}

int esp_dl_mp_write(esp_dl_mp_file_t *file, const void *buf, size_t num_bytes) {
    return (int)mp_write((mp_file_t *)file, buf, num_bytes);
}

off_t esp_dl_mp_seek(esp_dl_mp_file_t *file, off_t offset, int whence) {
    return mp_seek((mp_file_t *)file, offset, whence);
}

off_t esp_dl_mp_tell(esp_dl_mp_file_t *file) {
    return mp_tell((mp_file_t *)file);
}

void esp_dl_mp_close(esp_dl_mp_file_t *file) {
    mp_close((mp_file_t *)file);
}

int esp_dl_mp_printf(esp_dl_mp_print_t *print, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = mp_vprintf((mp_print_t *)print, fmt, args);
    va_end(args);
    return ret;
}
