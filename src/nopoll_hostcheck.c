/***************************************************************************
 *
 * Copyright (C) 1998 - 2017, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#include <nopoll_hostname_validation.h>

static int nopoll_hostname_str_compare(const char pattern, const char hostname);
static int nopoll_hostname_inet_compare(const char pattern, const char hostname);


static int nopoll_hostname_str_compare(const char pattern, const char hostname) {
  //TODO
  //Will do string comparison for both wildcard or without wildcard hostname 

}

static int nopoll_hostname_inet_compare(const char pattern, const char hostname) {
  //TODO
  // Will do IP comparison (IPV4 & IPV6)
}

int nopoll_match_hostname(const char *pattern, const char *hostname)
{
  char *match_pattern;
  char *host;
  int result = 0;
  match_pattern = nopoll_strdup(pattern);
  host = nopoll_strdup(hostname);

  if(match_pattern && host) {

      // TODO
      /* Compare hostname with the pattern */
      // If wildcard match is there then check for wildcard till two dots (.)
      // For IPV4 && IPV6 comparison wildcard is not supported. 
  nopoll_free(host);
  nopoll_free(match_pattern);
  return result;
  }
  return result;
}

