#include <stdio.h>
#include <stdlib.h>

#define ROWS 12
#define COLUMNS 25
enum enemyType{
	horizontal;
	vertical;
}

struct Enemy{
	int x;
	int y;
	char currentMapTile;
	int type;
}

struct Player
{
	int x;
	int y;
	char currentMapTile;
};

int main(void)
{
	char input;
	int i;
	
	char map[ROWS][COLUMNS] = {
	{'|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','X','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|', 0},
	{'|','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','|', 0}
	};
	
	struct Player p;
	
	struct Enemy eArray[Enemies] = {
		{3,4,'H', horizontal},
		{9,9,'V',vertical}
	}
	
	
	p.x =1;
	p.y = 7;
	p.currentMapTile = map[p.y][p.x];
	map[p.y][p.x] = 'P';
	do
	{
		/*system("clear");*/
		for(i = 0 ; i < 30 ; ++i)
		{
			putchar('\n');
		}
		
		for(i = 0 ; i < ROWS ; ++i)
		{
			printf("%s\n", map[i]);
		}
		scanf(" %c", &input);
		switch(input)
		{
			case '8':
			case 'w':
				if(p.y > 0 && map[p.y - 1][p.x] != '_' && map[p.y - 1][p.x] != '|')
				{
					map[p.y][p.x] = p.currentMapTile;
					--p.y;
					p.currentMapTile = map[p.y][p.x];
					map[p.y][p.x] = 'P';
				}
				break;
			case '4':
			case 'a':
				if(p.x > 0 && map[p.y][p.x -1] != '_' && map[p.y][p.x -1] != '|')
				{
					map[p.y][p.x] = p.currentMapTile;
					--p.x;
					p.currentMapTile = map[p.y][p.x];
					map[p.y][p.x] = 'P';
				}
				break;
			case '2':
			case 's':
				if(p.y < ROWS && map[p.y + 1][p.x] != '_' && map[p.y + 1][p.x] != '|')
				{
					map[p.y][p.x] = p.currentMapTile;
					++p.y;
					p.currentMapTile = map[p.y][p.x];
					map[p.y][p.x] = 'P';
				}
				break;
			case '6':
			case 'd':
			if(p.x < COLUMNS && map[p.y][p.x + 1] != '_' && map[p.y][p.x + 1] != '|')
				{
					map[p.y][p.x] = p.currentMapTile;
					++p.x;
					p.currentMapTile = map[p.y][p.x];
					map[p.y][p.x] = 'P';
				}
				break;
		}
		if(p.currentMapTile == 'X') {
			printf("Congrats you got out of the maze!\n");
			break;
		}
		
		
	}while(input != 'q');


	return 0;
}
