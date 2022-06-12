#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

#define HLighted    0x70
#define Nor         0x07


int main()
{

    char arr[40] = {'\0'};
    char *ptr = arr;
    int counter = 0, x = 0;
    int i = 0;
    int exit = 1;
    char ch;
    gotoxy(x, 0);
    textattr(HLighted);
    int end = 0;

    while(exit){
        ch = getch();
        //printf("%d",ch);
        switch(ch){
            case (-32):
                ch = getch();
                textattr(HLighted);
                switch(ch){
                    case 75:/* Left */
                        if(x != 0){
                            gotoxy(--x,0);
                            }
                            //textattr(Nor);
                        break;
                    case 77:/* Right */
                        if(x < counter){
                            gotoxy(++x,0);
                            }
                            //textattr(Nor);
                        break;
                        case 83:
                            textattr(Nor);
                            clrscr();
                            gotoxy(x,0);
                            for(i = x; i < counter; i++){
                                arr[i] = arr[i+1];
                            }
                            arr[i+1] = '\0';
                            counter --;
                            textattr(HLighted);
                            gotoxy(0,0);
                            printf("%s", arr);
                            x--;
                            gotoxy(x,0);
                            textattr(Nor);
                            break;

                    }
                break; /* End of extended keys */
                case 0:
                    ch = getch();
                    switch(ch){
                        case 71:

                            //x = counter-1;
                            gotoxy(0,0);
                            x=0;
                            break;
                        case 79:
                            x = counter-1;
                            gotoxy(x,0);
                            //counter++;
                            break;
                    }

            break;
            case 71:/* Home */
                    gotoxy(0,0);
                    //x = 0;
                    break;

            case 8:
                textattr(Nor);
                clrscr();
                x--;
                gotoxy(x,0);
                for(i = x; i < counter; i++){
                    arr[i] = arr[i+1];
                }
                arr[i] = '\0';
                counter --;
                textattr(HLighted);
                gotoxy(0,0);
                printf("%s", arr);
                textattr(Nor);
                break;
            case 13:/* Enter */
                textattr(Nor);
                arr[counter] = '\0';
                gotoxy(0,3);
                printf("\nSaved text : %s", arr);
                gotoxy(x,0);
                textattr(HLighted);
                break;
            case 27: /* ESC */
                exit = 0;
                break;
            /*case 79:
                x = counter-1;
                gotoxy(x,0);
                //counter++;
                break;*/

            default:
                textattr(HLighted);
                arr[x] = ch;
                ptr += counter;
                printf("%c", ch);
                counter++;
                x++;
                //getch();
                break;
        }
    }

    return 0;
}
