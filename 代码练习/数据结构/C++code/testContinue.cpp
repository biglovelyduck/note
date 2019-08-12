#include <iostream>
using namespace std;
int main(){
	for(int i=1;i<=10;i++){
		if(i%2==0){
			i++;
			continue;
		}
		cout<<i<<" ";
	}
	return 0;
} 
void play()
{
    int x, y, i, new_x, new_y, temp;
    int old_empty, move;
    char ch;

    while(1) 
    {
        move = 0;
        old_empty = empty;
        ch = getch(); 
        switch(ch) {
            case 97:    //左移  a
            case 104:   // h
            case 68:    // 左移方向键
                for(y = 0; y < 4; y++)
                    for(x = 0; x < 4; ) 
                    {
                        if(a[y][x] == 0) 
                        {
                            x++;
                            continue;
                        } 
                        else 
                        {
                            for(i = x + 1; i < 4; i++) 
                            {
                                if(a[y][i] == 0) 
                                {
                                    continue;
                                }
                                else 
                                {
                                    if(a[y][x] == a[y][i]) 
                                    {
                                        a[y][x] += a[y][i];
                                        a[y][i] = 0;
                                        empty++;
                                        break;
                                    }
                                    else 
                                    {
                                        break;
                                    }
                                }
                            }
                            x = i;
                        }
                    }
                for(y = 0; y < 4; y++)
                    for(x = 0; x < 4; x++) 
                    {
                        if(a[y][x] == 0) 
                        {
                            continue;
                        } 
                        else 
                        {
                            for(i = x; (i > 0) && (a[y][i-1] == 0); i--) 
                            {
                                a[y][i-1] = a[y][i];
                                a[y][i] = 0;
                                move = 1;
                            }
                        }
                    }
                break;
            case 100:   //右移 d 
            case 108:   // l
            case 67:    //右移方向键
                for(y = 0; y < 4; y++)
                    for(x = 3; x >= 0; ) 
                    {
                        if(a[y][x] == 0) 
                        {
                            x--;
                            continue;
                        } 
                        else 
                        {
                            for(i = x - 1; i >= 0; i--)
                            {
                                if(a[y][i] == 0)
                                {
                                    continue;
                                } 
                                else if(a[y][x] == a[y][i]) 
                                {
                                    a[y][x] += a[y][i];
                                    a[y][i] = 0;
                                    empty++;
                                    break;
                                } 
                                else 
                                {
                                    break;
                                }
                            }
                            x = i;
                        }
                    }
                for(y = 0; y < 4; y++)
                    for(x = 3; x >= 0; x--) 
                    {
                        if(a[y][x] == 0) 
                        {
                            continue;
                        } else 
                        {
                            for(i = x; (i < 3) && (a[y][i+1] == 0); i++) 
                            {
                                a[y][i+1] = a[y][i];
                                a[y][i] = 0;
                                move = 1;
                            }
                        }
                    }
                break;
            case 119:   //上移 w 
            case 107:   //k
            case 65:    //上移方向键
                for(x = 0; x < 4; x++)
                    for(y = 0; y < 4; ) 
                    {
                        if(a[y][x] == 0)
                        {
                            y++;
                            continue;
                        } 
                        else 
                        {
                            for(i = y + 1; i < 4; i++) 
                            {
                                if(a[i][x] == 0) 
                                {
                                    continue;
                                } 
                                else if(a[y][x] == a[i][x]) 
                                {
                                    a[y][x] += a[i][x];
                                    a[i][x] = 0;
                                    empty++;
                                    break;
                                } else 
                                {
                                    break;
                                }
                            }
                            y = i;
                        }
                    }
                for(x = 0; x < 4; x++)
                    for(y = 0; y < 4; y++) 
                    {
                        if(a[y][x] == 0) 
                        {
                            continue;
                        } 
                        else
                        {
                            for(i = y; (i > 0) && (a[i-1][x] == 0); i--) 
                            {
                                a[i-1][x] = a[i][x];
                                a[i][x] = 0;
                                move = 1;
                            }
                        }
                    }
                break;
            case 115:   //下移 s 
            case 106:   //j
            case 66:    //下移方向键
                for(x = 0; x < 4; x++)
                    for(y = 3; y >= 0; ) 
                    {
                        if(a[y][x] == 0) 
                        {
                            y--;
                            continue;
                        } 
                        else 
                        {
                            for(i = y - 1; i >= 0; i--) 
                            {
                                if(a[i][x] == 0) 
                                {
                                    continue;
                                } 
                                else if(a[y][x] == a[i][x])
                                {
                                    a[y][x] += a[i][x];
                                    a[i][x] = 0;
                                    empty++;
                                    break;
                                } 
                                else
                                {
                                    break;
                                }
                            }
                            y = i;
                        }
                    }
                for(x = 0; x < 4; x++)
                    for(y = 3; y >= 0; y--) 
                    {
                        if(a[y][x] == 0) 
                        {
                            continue;
                        } 
                        else 
                        {
                            for(i = y; (i < 3) && (a[i+1][x] == 0); i++) 
                            {
                                a[i+1][x] = a[i][x];
                                a[i][x] = 0;
                                move = 1;
                            }
                        }
                    }
                break;
            case 'Q':
            case 'q':
                game_over();
                break;
            default:
                continue;
                break;
        }
        if(empty <= 0)
            game_over();
        if((empty != old_empty) || (move == 1)) 
        { 
            do{
                new_x = rand() % 4;
                new_y = rand() % 4;
            }while(a[new_y][new_x] != 0);

            cnt_value(&new_y, &new_x);

            do {
                temp = rand() % 4;
            }while(temp == 0 || temp == 2);
            a[new_y][new_x] = temp + 1;
            empty--;
        }
        draw();
    }
}
