#ifndef MAINWINDOW
#define MAINWINDOW

#include <stdio.h>
#include <stdlib.h>
#include "model/modelarvore.h"

/**
 * @brief mainWindow
 */
void mainWindow();

/**
 * @brief viewInserir
 */
void viewInserir();

/**
 * @brief viewAlterar
 */
void viewAlterar();

/**
 * @brief viewBusca
 */
void viewBusca();

/**
 * @brief viewRemover
 */
void viewRemover();

/**
 * @brief viewCadastro
 */
void viewCadastro();

/**
 * @brief viewArvore
 * @param bd
 * @return nenhum
 * @pre nenhum
 * @post arvore mostrada no terminal
 */
void viewArvore(FILE *bd);

/**
 * @brief viewCarregar
 */
void viewCarregar();

/**
 * @brief viewConfirma
 * @return
 */
int viewConfirma();



#endif // MAINWINDOW

