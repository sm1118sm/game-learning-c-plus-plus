#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

    game.add(new Zombie("ÇãÁ¢ÇÑÁ»ºñ", "¡×", rand() % w, rand() % h));
    game.add(new Vampire("¹ìÆÄÀÌ¾îÂ¯", "¡Ú", rand() % w, rand() % h));
    game.add(new KGhost("¾îÂ¼´Ù±Í½Å", "¢¾", rand() % w, rand() % h));
    game.add(new Jiangshi("¸ø¸Ô¾îµµ°í", "¡ê", rand() % w, rand() % h, true));
    game.add(new Jiangshi("¸ø¸Ô¾î¼¼·Î", "¢Õ", rand() % w, rand() % h, false));
    game.add(new Smombi("½º¸öºñÂ¯Â¯", "¢Í", rand() % w, rand() % h));
    game.add(new Siangshi("½´ÆÛ°­½ÃÂ¯", "¢Â", rand() % w, rand() % h, true));
    game.add(new sGhost("³ªÀÇ¸ó½ºÅÍ", "¢Ó", rand() % w, rand() % h));
    game.play(500, 100);
	printf("---------------°ÔÀÓ Á¾·á---------------\n");
	system("pause");
	return 0;
}