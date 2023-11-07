/*!\file window.c
 * \brief 
 * \author 
 * \date 
 */

#include "claude.h"
#include "primitives.h"

static void dis(void) {
  //triangle_t t = { { {0, 0, 1.0f, 0.0f, 0.0f}, {300, 100, 0.0f, 1.0f, 0.0f}, {10, 230, 0.0f, 0.0f, 1.0f}  } };
  triangle_t t = { { {0, 0, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f}, {900, 300, 0.6f, 1.0f, 0.6f, 1.0f, 0.0f}, {10, 700, 0.6f, 0.6f, 1.0f, 0.0f, 1.0f}  } };
  GLuint * p = get_pixels();
  /* on dessine un triangle dessus */
  fill_triangle(&t);
  update_screen();  
}

/*!\brief créé la fenêtre, un screen 2D effacé en noir et lance une
 *  boucle infinie.*/
int main(int argc, char ** argv) {
  /* tentative de création d'une fenêtre pour GL4Dummies */
  if(!claude_init(argc, argv, /* args du programme */
		  "Claude' Hello World", /* titre */
		  960, 720, 960, 720) /* largeur_f, hauteur_f, largeur_e, hauteur_e */) {
    /* ici si échec de la création souvent lié à un problème d'absence
     * de contexte graphique ou d'impossibilité d'ouverture d'un
     * contexte OpenGL (au moins 3.2) */
    return 1;
  }

  
  gl4duwDisplayFunc(dis);
  apply_texture("images/leo.bmp");
  /* boucle infinie pour éviter que le programme ne s'arrête et ferme
   * la fenêtre immédiatement */
  gl4duwMainLoop();
  return 0;
}
