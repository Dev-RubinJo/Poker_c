//
//  main.c
//  poker
//
//  Created by yoo bin jo on 2016. 10. 7..
//  Copyright © 2016년 yoo bin jo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setHandList(char hand[][3], int handList[]);
void downSort(int handList[]);
void judgeWhoWin(int p1, int p2, int c1, int c2);
int checkWhatHand(char hand[][3], int handList[]);
int returnResult(int handList[]);
int player(char hand[][3], int handList[]);

int main()
{
    char hand[5][3];
    int handList[5];
    int p1, p2, c1, c2;
    printf("player1 ");
    p1 = player(hand, handList);
    c1 = checkWhatHand(hand, handList);
    printf("player2 ");
    p2 = player(hand, handList);
    c2 = checkWhatHand(hand, handList);
    
    judgeWhoWin(p1, p2, c1, c2);
    //printf("p1 : %d, p2 : %d\n", p1, p2);
    return 0;
}
void setHandList(char hand[][3], int handList[])
{
    for(int i = 0; i < 5; i++)
    {
        if(strcmp(hand[i], "2") == 0)
            handList[i] = 2;
        else if(strcmp(hand[i], "3") == 0)
            handList[i] = 3;
        else if(strcmp(hand[i], "4") == 0)
            handList[i] = 4;
        else if(strcmp(hand[i], "5") == 0)
            handList[i] = 5;
        else if(strcmp(hand[i], "6") == 0)
            handList[i] = 6;
        else if(strcmp(hand[i], "7") == 0)
            handList[i] = 7;
        else if(strcmp(hand[i], "8") == 0)
            handList[i] = 8;
        else if(strcmp(hand[i], "9") == 0)
            handList[i] = 9;
        else if(strcmp(hand[i], "10") == 0)
            handList[i] = 10;
        else if(strcmp(hand[i], "J") == 0)
            handList[i] = 11;
        else if(strcmp(hand[i], "Q") == 0)
            handList[i] = 12;
        else if(strcmp(hand[i], "K") == 0)
            handList[i] = 13;
        else if(strcmp(hand[i], "A") == 0)
            handList[i] = 14;
    }
    downSort(handList);
    for(int i = 0; i < 5; i++)
    {
        if(handList[0] == 14 && handList[1] == 5 && handList[2] == 4 && handList[3] ==3 && handList[4] == 2)
            handList[0] = 1;
    }
    downSort(handList);
    for(int i = 0; i < 5; i++)
    {
        if(handList[i] == 1 || handList[i] == 14)
            strcpy(hand[i], "A");
        else if(handList[i] == 13)
            strcpy(hand[i], "K");
        else if(handList[i] == 12)
            strcpy(hand[i], "Q");
        else if(handList[i] == 11)
            strcpy(hand[i], "J");
        else if(handList[i] == 10)
            strcpy(hand[i], "10");
        else if(handList[i] == 9)
            strcpy(hand[i], "9");
        else if(handList[i] == 8)
            strcpy(hand[i], "8");
        else if(handList[i] == 7)
            strcpy(hand[i], "7");
        else if(handList[i] == 6)
            strcpy(hand[i], "6");
        else if(handList[i] == 5)
            strcpy(hand[i], "5");
        else if(handList[i] == 4)
            strcpy(hand[i], "4");
        else if(handList[i] == 3)
            strcpy(hand[i], "3");
        else if(handList[i] == 2)
            strcpy(hand[i], "2");
    }
}
void downSort(int handList[])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4 - i; j++)
        {
            if(handList[j] < handList[j+1])
            {
                int temp = handList[j];
                handList[j] = handList[j+1];
                handList[j+1] = temp;
            }
        }
    }
}
int checkWhatHand(char hand[][3], int handList[])
{
    int check;
    if (((handList[0] == handList[1]) && (handList[1] == handList[2]) && (handList[2] == handList[3]) && (handList[3] != handList[4])) || ((handList[0] != handList[1]) && (handList[1] == handList[2]) && (handList[2] == handList[3]) && (handList[3] == handList[4])))
    {
        printf("%s Four of a Kind\n", hand[1]);
        check = 6;
    }
    else if(((handList[0] == handList[1]) && (handList[1] == handList[2]) && (handList[2] != handList[3]) && (handList[3] == handList[4])) || ((handList[0] == handList[1]) && (handList[1] != handList[2]) && (handList[2] == handList[3]) && (handList[3] == handList[4])))
    {
        printf("%s %s Full House\n", hand[1], hand[4]);
        check = 5;
    }
    else if (handList[1] == (handList[0] - 1) && handList[2] == (handList[1] - 1) && handList[3] == (handList[2] - 1) && handList[4] == (handList[3] - 1))
    {
        printf("%s - High Straight\n", hand[0]);
        check = 4;
    }
    else if ((((handList[0] == handList[1]) && (handList[1] == handList[2]) && (handList[2] != handList[3]) && (handList[3] != handList[4])) || ((handList[0] != handList[1]) && (handList[1] == handList[2]) && (handList[2] == handList[3]) && (handList[3] != handList[4])) || ((handList[0] != handList[1]) && (handList[1] != handList[2]) && (handList[2] == handList[3]) && (handList[3] == handList[4]))))
    {
        printf("%s Three of a Kind\n", hand[2]);
        check = 3;
    }
    else if (((handList[0] == handList[1]) && (handList[1] != handList[2]) && (handList[2] == handList[3]) && (handList[3] != handList[4])) || ((handList[0] != handList[1]) && (handList[1] == handList[2]) && (handList[2] != handList[3]) && (handList[3] == handList[4])) || ((handList[0] == handList[1]) && (handList[1] != handList[2]) && (handList[2] != handList[3]) && (handList[3] == handList[4])))
    {
        printf("%s %s Two Pair\n", hand[1], hand[3]);
        check = 2;
    }
    else if (((handList[0] == handList[1]) && (handList[1] != handList[2]) && (handList[2] != handList[3]) && (handList[3] != handList[4])) || ((handList[0] != handList[1]) && (handList[1] == handList[2]) && (handList[2] != handList[3]) && (handList[3] != handList[4])) || ((handList[0] != handList[1]) && (handList[1] != handList[2]) && (handList[2] == handList[3]) && (handList[3] != handList[4])) || ((handList[0] != handList[1]) && (handList[1] != handList[2]) && (handList[2] != handList[3]) && (handList[3] == handList[4])))
    {
        if (handList[0] == handList[1])
            printf("%s One Pair\n", hand[0]);
        else if (handList[1] == handList[2])
            printf("%s One Pair\n", hand[1]);
        else if (handList[2] == handList[3])
            printf("%s One Pair\n", hand[2]);
        else if (handList[3] == handList[4])
            printf("%s One Pair\n", hand[3]);
        check = 1;
    }
    else
    {
        printf("No Pair\n");
        check = 0;
    }
    return check;
}
int returnResult(int handList[])
{
    int result = 0;
    for(int i = 0; i < 5; i++)
        result += handList[i];
    return result;
}
int player(char hand[][3], int handList[])
{
    int result;
    printf("카드를 입력하세요. \n");
    for(int i = 0; i < 5; i++)
        scanf("%s", hand[i]);
    setHandList(hand, handList);
    result = returnResult(handList);
    return result;
}
void judgeWhoWin(int p1, int p2, int c1, int c2)
{
    if(c1 > c2)
        printf("player1 Win\n");
    else if(c1 < c2)
        printf("player2 Win\n");
    else
    {
        if(p1 > p2)
            printf("player1 Win\n");
        else if(p1 < p2)
            printf("player2 Win\n");
        else
            printf("Same Point, Nobody Win\n");
    }
}
