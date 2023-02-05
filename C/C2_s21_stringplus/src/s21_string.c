#include "s21_string.h"

size_t s21_strlen(const char *str) {
  register const char *s = NULL;
  if (str != NULL) {
    s = str;
    for (; *s; ++s)
      ;
  }
  return (size_t)(s - str);
}

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;
  s21_size_t len1 = s21_strlen(str1);
  for (s21_size_t i = 0; i < len1 + 1 && result == 0; i++) {
    if (str1[i] != str2[i]) {
      result = (int)(str1[i] - str2[i]);  // why?
    }
  }
  return result;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0; i++) {
    if (str1[i] != str2[i]) {
      result = (int)(str1[i] - str2[i]);  // why?
    }
  }
  return result;
}

char *s21_strcpy(char *dest, const char *src) {
  char *result = dest;
  s21_size_t len = s21_strlen(src);
  for (s21_size_t i = 0; i < len + 1; i++) {
    dest[i] = src[i];
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *result = dest;
  for (s21_size_t i = 0; i < n; i++) {
    if (src[i] != '\0') {
      dest[i] = src[i];
    } else {
      dest[i] = '\0';
    }
  }
  return result;
}

char *s21_strcat(char *dest, const char *src) {
  char *result = dest + s21_strlen((char *)dest);
  while (*src) *result++ = *src++;
  *result = '\0';
  return dest;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  char *result = dest;
  s21_size_t len1 = s21_strlen((char *)dest);
  for (s21_size_t i = len1; i < n + len1 && *src != '\0'; i++) {
    dest[i] = *src++;
  }
  return result;
}

char *s21_strchr(const char *str, int c) {
  char *find = s21_NULL;
  char *ptr = (char *)str;
  if (ptr != NULL) {
    if (c != '\0') {
      for (; *ptr && find == s21_NULL; *ptr == c ? find = ptr : ptr++)
        ;
    } else {
      find = &ptr[my_strlen(str)];
    }
  }
  return find;
}
// char *s21_strchr(const char *str, int c) {
//   char *result = s21_NULL;
//   char *str_p = (char *) str;
//   s21_size_t len = s21_strlen(str);
//   for (s21_size_t i = 0; i < len && result == s21_NULL; i++) {
//     if (str_p[i] == (char) c) {
//       result = str_p + i;
//     }
//   }
//
//   return result;
// }

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  char *str_p = (char *)str;
  s21_size_t len = s21_strlen(str) + 1;
  for (s21_size_t i = 0; i < len; i++) {
    if (str_p[i] == (char)c) {
      result = str_p + i;
    }
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *search = (char *)needle, *string = (char *)haystack, *res = NULL;
  if (string && *string != '\0' && needle && *needle != '\0') {
    for (int i = 0; string[i] && res == NULL; i++) {
      if (string[i] == *search &&
          !s21_memcmp(search, &string[i], s21_strlen(search)))
        res = &string[i];
    }
  } else if (string != NULL && search && *search == '\0')
    res = string;
  return res;
}
char *s21_strtok(char *str, const char *delim) {
  char *start = NULL;
  static char *match = NULL;
  if (str && *str != '\0' && (start = str) != NULL && delim != NULL) {
    if ((match = s21_strpbrk(str, delim)) != NULL && *match) {
      for (*match++ = '\0'; s21_strchr(delim, *match) && *match != '\0';
           match++)
        ;
      if (*start == '\0' && match != NULL) {
        start = (*match != '\0') ? s21_strtok(match, delim) : NULL;
      }
    }
  } else if (delim != NULL && match != NULL && *match) {
    start = s21_strtok(match, delim);
  }
  return start;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t pos = -1;
  unsigned char *str_p = (unsigned char *)str;
  for (s21_size_t i = 0; i < n && (int)pos == -1; i++) {
    if (str_p[i] == (unsigned char)c) {
      pos = i;
    }
  }
  return (int)pos == -1 ? s21_NULL : (str_p + pos);
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;
  unsigned char *str1_p = (unsigned char *)str1;
  unsigned char *str2_p = (unsigned char *)str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (str1_p[i] != str2_p[i]) {
      result = str1_p[i] - str2_p[i];
      i = n;
    }
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *src_p = (unsigned char *)src;
  unsigned char *dest_p = (unsigned char *)dest;
  for (s21_size_t i = 0; i < n; i++) {
    dest_p[i] = src_p[i];
  }
  return dest_p;
}

// void *s21_memmove(void *dest, const void *src, size_t n) {
//   unsigned char *dest_p = (unsigned char *) dest;
//   if (dest_p != s21_NULL) {
//     unsigned char buf[n];
//     s21_memcpy(buf, src, n);
//     for (s21_size_t i = 0; i < n; i++) {
//       dest_p[i] = buf[i];
//     }
//   }
//   return dest_p;
// }

void *s21_memmove(void *dest, const void *src, size_t n) {
  register char *dst = (char *)dest;
  register char *sorce = (char *)src;
  if (dst < sorce) {
    for (; n; *dst = *sorce, n--, ++dst, sorce++)
      ;
  } else {
    dst = (char *)dest + (n - 1);
    sorce = (char *)src + (n - 1);
    for (; n; *dst = *sorce, n--, dst--, sorce--)
      ;
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_p = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    str_p[i] = c;
  }
  return str_p;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  s21_size_t result = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < len1 && flag == 0; i++) {
    for (s21_size_t j = 0; j < len2 && flag == 0; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
    }
    if (flag == 0) {
      result++;
    }
  }
  return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int i = 0, flag = 0;
  while (flag == 0 && str1[i] != '\0') {
    for (int j = 0; str2[j] != '\0' && flag == 0; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
    }
    if (flag == 0) i++;
  }
  return flag == 0 ? s21_NULL : ((char *)str1 + i);
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t count = 0, flag = 0;
  s21_size_t len1 = s21_strlen(str1);
  for (s21_size_t i = 0; i < len1; i++) {
    if (count == i) {
      for (s21_size_t j = 0; str2[j] != '\0' && flag == 0; j++) {
        if (str1[i] == str2[j]) {
          count++;
          flag = 1;
        }
      }

    } else {
      len1 = i;
    }
    flag = 0;
  }
  return count;
}

char *s21_strerror(int errnum) {
  static char error[256] = "";
  char *err_s[] = s21_error;
#if defined __MACH__ || __APPLE__
  if (errnum >= 0 && errnum < 107) {
    s21_strcpy(error, err_s[errnum]);
  } else {
    s21_sprintf(error, "Unknown error: %d", errnum);
  }
#else
  if (errnum >= 0 && errnum < 134) {
    s21_strcpy(error, err_s[errnum]);
  } else {
    s21_sprintf(error, "Unknown error %d", errnum);
  }
#endif
  return error;
}

void *s21_to_upper(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *buf_str =
      calloc(len + 10, sizeof(char));  // check to null, that memmory allocated
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      buf_str[i] = (char)(str[i] - 32);
    } else {
      buf_str[i] = str[i];
    }
  }
  return buf_str;
}

void *s21_to_lower(const char *str) {
  s21_size_t len = s21_strlen(str);
  char *buf_str = calloc(len + 10, sizeof(char));
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      buf_str[i] = (char)(str[i] + 32);
    } else {
      buf_str[i] = str[i];
    }
  }
  return buf_str;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *res = NULL;
  if (src != NULL && str != NULL) {
    s21_size_t len_src = s21_strlen(src);
    if (len_src >= start_index) {
      s21_size_t len_str = s21_strlen(str);
      res = calloc(2 + len_src + len_str, sizeof(char));
      if (res != NULL) {
        s21_memmove(res, src, start_index);
        s21_memmove(res + start_index, str, len_str);
        s21_memmove(res + start_index + len_str, src + start_index,
                    len_src - start_index);
        *(res + len_str + len_src) = '\0';
      }
    }
  }
  return (void *)res;
}

// void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
//   int pos = 0;
//   char *buf_str = s21_NULL;
//   if (str != s21_NULL && src != s21_NULL) {
//     s21_size_t len_str = s21_strlen(src);
//     s21_size_t len = len_str + s21_strlen(str);
//     if (len > 0 && start_index <= len_str) {
//       buf_str = calloc(len + 10, sizeof(char));
//       for (s21_size_t i = 0; i < len; i++) {
//         if (i == start_index) {
//           for (int j = 0; str[j] != '\0'; j++, i++) {
//             buf_str[i] = str[j];
//           }
//           i--;
//         } else {
//           buf_str[i] = src[pos];
//           pos++;
//         }
//       }
//     }
//   } else if (str == s21_NULL) {
//     buf_str = (char *) src;
//   }
//   return buf_str;
// }

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = NULL;
  if (src != NULL) {
    s21_size_t start = 0, end = s21_strlen(src);
    if (start != end) {
      if (trim_chars != NULL && !(trim_chars && *trim_chars == 0)) {
        for (; s21_strchr(trim_chars, src[start]) && start < end; start++)
          ;
        for (; s21_strchr(trim_chars, src[end]) && end > start; end--)
          ;
      } else {
        for (; s21_strchr("\r\n\t\v\f ", src[start]) && start < end; start++)
          ;
        for (; s21_strchr("\r\n\t\v\f ", src[end]) && end > start; end--)
          ;
      }
    }
    res = calloc(end - start + 2, sizeof(char));
    if (res != NULL) {
      s21_memmove(res, &src[start], end - start + 1);
      *(res + end - start + 1) = '\0';
    }
  }
  return (void *)res;
}

// void *s21_trim(const char *src, const char *trim_chars) {
//   s21_size_t len = s21_strlen(src);
//   s21_size_t flag_i = 0, flag_j = 0, start = 0, end = len - 1;
//   char *buf_str = calloc(len + 10, sizeof(char));
//   if (len > 0) {
//     if (trim_chars == s21_NULL || trim_chars[0] == '\0') {
//       trim_chars = " ";
//     }
//     s21_size_t i = 0;
//     for (; i < len && start == i; i++) {
//       for (s21_size_t tr = 0; trim_chars[tr] != '\0' && flag_i == 0; tr++) {
//         if (src[i] == trim_chars[tr]) {
//           start = i + 1;
//           flag_i = 1;
//         }
//       }
//       flag_i = 0;
//     }
//     for (s21_size_t j = len - 1; j >= i && end == j; j--) {
//       for (s21_size_t tr = 0; trim_chars[tr] != '\0' && flag_j == 0; tr++) {
//         if (src[j] == trim_chars[tr]) {
//           end = j - 1;
//           flag_j = 1;
//         }
//       }
//       flag_j = 0;
//     }
//     for (int j = 0; start <= end; j++, start++) {
//       buf_str[j] = src[start];
//     }
//   } else {
//   }
//   return buf_str;
// }
