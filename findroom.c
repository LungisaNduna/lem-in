#include "lem_in.h"

room_t   *findroom(int roomno, room_t *rooms)
{
        room_t *temp;

        temp = rooms;
        while (temp->next != NULL)
        {
                if (temp->roomno == roomno)
                        return (temp);
                temp = temp->next;
        }
        return (NULL);
}

