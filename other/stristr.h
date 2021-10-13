/**
 * stristr - Case insensitive strstr()
 * @haystack: Where we will search for our @needle
 * @needle:   Search pattern.
 *
 * Description:
 * This function is an ANSI version of strstr() with case insensitivity.
 *
 * It is a commodity funciton found on the web, cut'd, 'n', pasted..
 * URL: http://www.brokersys.com/snippets/STRISTR.C
 *
 * Hereby donated to public domain.
 *
 * Returns:  char *pointer if needle is found in haystack, otherwise NULL.
 *
 * Rev History:  01/20/05  Joachim Nilsson   Cleanups
 *               07/04/95  Bob Stout         ANSI-fy
 *               02/03/94  Fred Cole         Original
 */


char* stristr(const char *haystack, const char *needle);

