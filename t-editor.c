#include <stdio.h>
#include <string.h>
void edit_line(char* buffer, int current_line)
{
  for (int i = 0; i < current_line; i++)
  {
    buffer = strchr(buffer, '\n') + 1;
  }
  char* line_end  = strchr(buffer, '\n');
  char saved[1024] = { 0 };
  strcpy(saved, line_end);
  scanf("%s", buffer);
  strcpy(buffer + strlen(buffer), saved);
}
int main(int argc, char** argv)
{
  FILE* f = fopen(argv[1], "r");
  char buffer[1024] = {0};
  fread(buffer, 1024, 1, f);
  fclose(f);
  int current_line = 0;
  for (int i = 0; i < 1024; i++)
  {
    scanf("%d", current_line);
    printf("Содержимое:\n%s\n", buffer);
    edit_line(buffer, current_line);
    f = fopen(argv[1], "w");
    fwrite(buffer, strlen(buffer), 1, f);
    fclose(f);
    if (i == 1023)
    {
      puts("To do more than 1023 edits at one time, you will need to buy t-txt for 99 rubles in Moscow Planetarium on tuesday, 17:00\n");
      break;
      return (0);
    }
  }
}
