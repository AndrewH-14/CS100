#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "PlaylistNode.h"

void PrintMenu(char* title) {
    char userInput = ' ';
    char c = ' ';
    PlaylistNode* head = NULL;

    while (userInput != 'q') {
        printf("%s PLAYLIST MENU\n", title);
        printf("a - Add song\n");
        printf("r - Remove song\n");
        printf("c - Change position of song\n");
        printf("s - Output songs by specific artist\n");
        printf("t - Output total time of playlist (in seconds)\n");
        printf("o - Output full playlist\n");
        printf("q - Quit\n");

        printf("\nChoose an option:\n");
        scanf(" %c", &userInput);

        if (userInput == 'a') {
            while ((c = getchar()) != EOF && c != '\n');
            char uniqueID[50];
            char songName[50];
            char artistName[50];
            int songLength;

            printf("ADD SONG\n");
            printf("Enter song's unique ID:\n");
            scanf(" %s", uniqueID);
            printf("Enter song's name:\n");
            scanf(" %[^\n]s", songName);
            printf("Enter artist's name:\n");
            scanf(" %[^\n]s", artistName);
            printf("Enter song's length (in seconds):\n\n");
            scanf(" %d", &songLength);

            PlaylistNode* newNode = (PlaylistNode*)malloc(sizeof(PlaylistNode));
            newNode = CreatePlaylistNode(newNode, uniqueID, songName, artistName, songLength, NULL);
            head = addPlaylistNode(head, newNode);
            userInput = ' ';
        }
        else if (userInput == 'r') {
            while ((c = getchar()) != EOF && c != '\n');
            char uniqueID[50];
            printf("REMOVE SONG\n");
            printf("Enter song's unique ID:\n");
            scanf(" %s", uniqueID);
            head = RemoveNode(head, uniqueID);
            userInput = ' ';
        }
        else if (userInput == 'c') {
            while ((c = getchar()) != EOF && c != '\n');
            int curPos;
            int newPos;
            printf("CHANGE POSITION OF SONG\n");
            printf("Enter song's current position:\n");
            scanf(" %d", &curPos);
            printf("Enter new position for song:\n");
            scanf(" %d", &newPos);
            head = ChangePosition(head, curPos, newPos);
            userInput = ' ';
        }
        else if (userInput == 's') {
            printf("OUTPUT SONGS BY SPECIFIC ARTIST\n");
            char name[50];
            printf("Enter artist's name:\n");
            scanf(" %[^\n]s", name);
            PrintSpecificArtist(head, name);
            userInput = ' ';
        }
        else if (userInput == 't') {
            int sumTime = 0;
            printf("OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)\n");
            for (PlaylistNode* cur = head; cur != NULL; cur = cur->nextNodePtr) {
                sumTime = sumTime + cur->songLength;
            }
            printf("Total time: %d seconds\n\n", sumTime);
            userInput = ' ';
        }
        else if (userInput == 'o') {
            printf("%s - OUTPUT FULL PLAYLIST\n", title);
            OutputTotalPlaylist(head);
            userInput = ' ';
        }
    }
}

int main() {

    char title[50];

    printf("Enter playlist's title:\n\n");
    scanf(" %[^\n]s", title);
    PrintMenu(title);

    return 0;
}