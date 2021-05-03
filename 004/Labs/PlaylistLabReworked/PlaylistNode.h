#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

typedef struct playlistnode {
    char uniqueID[50];
    char songName[50];
    char artistName[50];
    int songLength;
    struct playlistnode* nextNodePtr;
} PlaylistNode;

PlaylistNode* CreatePlaylistNode(PlaylistNode* node, char* uniqueID, char* songName, char* artistName, int songLength, PlaylistNode* nextLoc);

void InsertPlaylistNodeAfter(PlaylistNode* node, PlaylistNode* newNode);

void SetNextPLaylistNode(PlaylistNode* curNode, PlaylistNode* newNode);

PlaylistNode* GetNextPlaylistNode(PlaylistNode* node);

void PrintPlaylistNode(PlaylistNode* node);

PlaylistNode* addPlaylistNode(PlaylistNode* head, PlaylistNode* newNode);

PlaylistNode* RemoveNode(PlaylistNode* head, char* uniqueID);

void PrintSpecificArtist(PlaylistNode* head, char* name);

void OutputTotalPlaylist(PlaylistNode* head);

int GetLengthOfList(PlaylistNode* head);

PlaylistNode* ChangePosition(PlaylistNode* head, int curPos, int newPos);

#endif
