#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "PlaylistNode.h"

PlaylistNode* CreatePlaylistNode(PlaylistNode* node, char* uniqueID, char* songName, char* artistName, int songLength, PlaylistNode* nextLoc) {
    strcpy(node->uniqueID, uniqueID);
    strcpy(node->artistName, artistName);
    strcpy(node->songName, songName);
    node->songLength = songLength;
    node->nextNodePtr = nextLoc;
    return node;
}

void InsertPlaylistNodeAfter(PlaylistNode* node, PlaylistNode* newNode) {
    PlaylistNode* tmpNext = NULL;

    tmpNext = node->nextNodePtr;
    node->nextNodePtr = newNode;
    newNode->nextNodePtr = tmpNext;
}

void SetNextPlaylistNode(PlaylistNode* curNode, PlaylistNode* newNode) {
    curNode->nextNodePtr = newNode;
}

PlaylistNode* GetNextPlaylistNode(PlaylistNode* node) {
    return node->nextNodePtr;
}

void PrintPlaylistNode(PlaylistNode* node) {
    printf("Unique ID: %s\n", node->uniqueID);
    printf("Song Name: %s\n", node->songName);
    printf("Artist Name: %s\n", node->artistName);
    printf("Song Length (in seconds): %d\n\n", node->songLength);
}

PlaylistNode* addPlaylistNode(PlaylistNode* head, PlaylistNode* newNode) {
    if (head == NULL) {
        return newNode;
    }
    else {
        for (PlaylistNode* cur = head; cur != NULL; cur = cur->nextNodePtr) {
            if (cur->nextNodePtr == NULL) {
                cur->nextNodePtr = newNode;
                break;
            }
        } 
    }
    return head;  
}

PlaylistNode*  RemoveNode(PlaylistNode* head, char* uniqueID) {
    if (head == NULL) return NULL;

    if (strcmp(uniqueID, head->uniqueID) == 0) {
        printf("\"%s\" removed.\n\n", head->songName);
        PlaylistNode* toBeDeleted = head;
        head = head->nextNodePtr;
        free(toBeDeleted);
        return head;
    }

    head->nextNodePtr = RemoveNode(head->nextNodePtr, uniqueID);
    return head;
}

void PrintSpecificArtist(PlaylistNode* head, char* name) {
    int i = 1;
    for (PlaylistNode* cur = head; cur != NULL; cur = cur->nextNodePtr) {
        if (strcmp(cur->artistName, name) == 0) {
            printf("%d.\n", i);
            PrintPlaylistNode(cur);
        }
        i++;
    }
}

void OutputTotalPlaylist(PlaylistNode* head) {
    if (head == NULL) {
        printf("Playlist is empty\n\n");
    }
    PlaylistNode* cur = head;
    int i = 1;
    while (cur != NULL) {
        printf("%d.\n", i);
        PrintPlaylistNode(cur);
        cur = GetNextPlaylistNode(cur);
        i++;
    }
}

int GetLengthOfList(PlaylistNode* head) {
    int count = 0;
    for (PlaylistNode* cur = head; cur != NULL; cur = cur->nextNodePtr) {
        count++;
    }
    return count;
}

PlaylistNode* ChangePosition(PlaylistNode* head, int curPos, int newPos) {
    int pos = 1;
    int numNodes = GetLengthOfList(head);
    PlaylistNode* cur;
    for (cur = head; cur != NULL; cur = cur->nextNodePtr) {
        if (pos == curPos) {
            break;
        }
        pos++;
    }
    //printf("%s\n", cur->uniqueID);

    if (head == cur) {
        head = head->nextNodePtr;
    }
    else {
        PlaylistNode* prev = head;

        while(prev->nextNodePtr != NULL) {

            if (prev->nextNodePtr == cur) {
                break;
            }
            prev = prev->nextNodePtr; 
        }

        prev->nextNodePtr = prev->nextNodePtr->nextNodePtr;
    }

    if (newPos == 1) {
        cur->nextNodePtr = head;
        return cur;
    }
    else if (newPos == numNodes) {
        for (PlaylistNode* current = head; current != NULL; current = current->nextNodePtr) {
            if (current->nextNodePtr == NULL) {
                current->nextNodePtr = cur;
                cur->nextNodePtr = NULL;
            }
        }
        return head;
    }
    else {
        //printf("...\n");
        int i = 1;
        PlaylistNode* before = NULL;
        PlaylistNode* after = NULL;
        for (PlaylistNode* current = head; current != NULL; current = current->nextNodePtr) {
            if (i == (newPos - 1)) {
                before = current;
                //printf("%s\n", before->uniqueID);
            }
            if (i == (newPos)) {
                after = current;
            }
            i++;
        }
        //printf("...\n");
        //printf("%s\n", before->uniqueID);
        //printf("%s\n", cur->uniqueID);
        before->nextNodePtr = cur;
        cur->nextNodePtr = after;
    }
    printf("\"%s\" moved to position %d\n\n", cur->songName, newPos);
    return head;
}
