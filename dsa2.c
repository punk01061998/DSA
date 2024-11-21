C Program - String Pattern Replacement
#include <stdio.h>
#include <string.h>
int main() {
 char STR[100], PAT[100], REP[100], ans[200];
 int i, j, m = 0, flag = 0, c = 0;
 printf("Enter the MAIN String:\n");
 gets(STR);
 printf("\nEnter a PATTERN string:\n");
 gets(PAT);
 printf("\nEnter a REPLACE string:\n");
 gets(REP);
 i = j = 0;
 while (STR[i] != '\0') {
 if (STR[i] == PAT[m]) {
 m++;
 if (PAT[m] == '\0') {
 for (int k = 0; REP[k] != '\0'; k++) {
 ans[j++] = REP[k];
 }
 m = 0;
 }
 } else {
 ans[j++] = STR[i];
 m = 0;
 }
 i++;
 }
 ans[j] = '\0';
 if (m == 0) {
 printf("The RESULTANT string is: %s\n", ans);
 } else {
 printf("Pattern not found!\n");
 }
 return 0;
}