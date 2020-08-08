#include "view/mainwindow.h"
#include "model/modelarquivo.h"
#include "model/modelarvore.h"

int main(void)
{
//    mainWindow();

    FILE* bd = abrirArquivoBinario("teste.bin", "wb+");

    criarHeader(bd);

    insereChave(bd, 10, 0);
    insereChave(bd, 20, 0);
    insereChave(bd, 30, 0);
    insereChave(bd, 40, 0);
    insereChave(bd, 50, 0);
    insereChave(bd, 60, 0);
    insereChave(bd, 70, 0);
    insereChave(bd, 80, 0);
    insereChave(bd, 90, 0);
    insereChave(bd, 100, 0);
//    insereChave(bd, 110, 0);
//    insereChave(bd, 120, 0);
//    insereChave(bd, 130, 0);
//    insereChave(bd, 140, 0);
//    insereChave(bd, 150, 0);
//    insereChave(bd, 160, 0);
//    insereChave(bd, 170, 0);
//    insereChave(bd, 180, 0);
//    insereChave(bd, 190, 0);
//    insereChave(bd, 200, 0);
//    insereChave(bd, 210, 0);
//    insereChave(bd, 220, 0);
//    insereChave(bd, 230, 0);
//    insereChave(bd, 240, 0);
//    insereChave(bd, 250, 0);
//    insereChave(bd, 260, 0);
//    insereChave(bd, 270, 0);
//    insereChave(bd, 280, 0);
//    insereChave(bd, 290, 0);
//    insereChave(bd, 300, 0);
//    insereChave(bd, 310, 0);








    viewArvore(bd);
    return 0;
}
