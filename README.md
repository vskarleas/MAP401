# MAP401 Software Project

## Notes

This library isn't in synchromisation with Turing. It requires an SFTP connection via the Cyberduck software. You can work locally on your machine and overwrite the files later on DLST files server via the SFTP connection.

Below you can find the releases of the code as well as a callendar of the latest synchronisations with the server at the university.

## Changelog

* V1.1:24/01/2023 : Files for Tache 1 were installed on Turing and all the uncompleted functiomns were completed and tested.
* V1.2:24/01/2023 : Files for Tache 2 were installed and completed all the types required from the functions
* V1.3:24/01/2023 : Files for Tache 3 were installed
* V2.1:24/01/2023 : Provided software and code from previous projects for the implementaion of the robot. Fixed any undefined parameters and variables from the code that was transcoded into this project
* V2.2:25/01/2023 : Redefined the sequnces_functions.c files provided from the chef of project and completed any linking that was required for the file to work with th rest of files
* V2.3:25/01/2023 : Completed the algorythm and fixed minor bugs at contour.c
* V2.3-2:25/01/2023 : Project was divided into new subfolders for better clarification. Any non important files were deleted and published this version on GitHub repositry.
* V3.1:27/01/2023 : Fixed an issue on the algorithm that fins the starting point (it was checikng for a free pixel on right of every specific pixel and not to the north). More functionality added as well as follows:
  * Verfication of number of arguments was added
  * Fixed minor bugs on geom2d.c
  * Updated files verifications on Tache1, Tache2 and Tache3 folders
* V3.2:27/01/2023 : Devided Tache3 on contour.c sections according to the requirements of the compte-rendu. The code for Part 1 is as a comment "//" and the rest is the functional code for the Part 2.
* V3:2.1:30:01:2023 : Corrections according to the message "Il ne faut pas utiliser directement les champs de la structure Image, mais il faut utiliser les fonctions largeur_image, hauteur_image, get_pixel_image, set_pixel_image, etc ..." for Tache 1 and Tache 3 file image.c
* V3:2.2:30:01:2023 : Automating the test for contour.c
* V4.1:30:01:2023 : Tache 4 has been completed and all the images are now created by using the test test_postscript. In this version there was also changes to the function algo_contour . Now this function only takes an image and the file_name to print out the countour. On the same time it returns the contour. It's this function that will be changed on Tache 5 in order to write multiple contours in one file (a variable will control it)
* V4.2: 31:01:2023 : Correction de la fonction de creation des images EPS pour qu'il ne sont pas affiché à l'invers
* V5.1:31:01:2023 : Commence le Tache 5. Il ya des correctiosn qu'on doit faire avec le while dans la fonction algo_contours
* V5.2:31:01:2023 : Part 1 of Task 5 has been completed and any errors has been fixed. The program was remodified to better server and accelerate the algorithms.
* V5.3:31:01:2023 : All the task file has been compleetd. You can find the files that were asked to be created in the corresponding folder of Tache5
* V5.4:06/02/2023 : Correction par apport l'email de 6 fevrier 2023

## Sync

1. 24/01/2023: Turing -> PC (V2.1)
2. 27/01/2023: PC (V3.1) -> Turing (Links for Tache 1 and 2 sent to prof)
3. 31/01/2023: PC (V4.2) -> Turing (Links for Tache 3 and 4 sent to prof)
4. 31/01/2023: PC (V5.3) -> Turing
