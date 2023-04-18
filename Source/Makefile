#############################################################################
# Fichier Makefile 
# UE MAP401 - DLST - UGA - 2022/2023
#############################################################################
#############################################################################
# This version of make file includes tests for all the previous Taches
#############################################################################
# utilisation des variables internes $@ $< $^ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond � toutes les d�pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_image test_geom test_contour test_postscript test_mask test_simplification test_approx test_degree2 test_degree3 test_approx3


#############################################################################
# definition des regles
#############################################################################

########################################################
# la r�gle par d�faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
image.o : image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_image.o : test_image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

geom2d.o : geom2d.c geom2d.h contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_geom.o : test_geom.c geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_geom"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

contour.o : contour.c contour.h image.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

sequence_point.o : sequence_point.c sequence_point.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module sequence_point"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_contour.o : test_contour.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_postscript.o : test_postscript.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_postscript"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_mask.o : test_mask.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_mask"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_approx.o : test_approx.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_approx"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_approx3.o : test_approx3.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_approx3"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_degree2.o : test_degree2.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_degree2"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_degree3.o : test_degree3.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_degree3"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_simplification.o : test_simplification.c contour.h image.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_simplification"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		
########################################################
# regles explicites de creation des executables

test_image : test_image.o image.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_geom : test_geom.o geom2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_contour : test_contour.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_postscript : test_postscript.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_mask : test_mask.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_approx : test_approx.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_approx3 : test_approx3.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@


test_degree2 : test_degree2.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_degree3 : test_degree3.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

test_simplification : test_simplification.o contour.o image.o geom2d.o sequence_point.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@

# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
