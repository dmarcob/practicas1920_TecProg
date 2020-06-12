------------------------------------------------------------------
-- Autor: Diego Marco, 755232
-- Fichero: Main.hs
-- Fecha: 12-06-2020
-- Coms: Solución adaptada de: https://sudonull.com/post/145971-Solving-the-Haskell-Missionary-and-Cannibal-Problem
------------------------------------------------------------------

import Cannibals

main = do
   -- Con una barca de capacidad = 2 pasajeros, el número máximo de 
   -- canibales y misioneros posibles en cada orilla es de 3    

   print "---canibales=2. misioneros=2. Capacidad barca=2---"
   cannibals 2 2
   
   print "---canibales=3. misioneros=3. Capacidad barca=2---"
   cannibals 3 2

  -- Con una barca de capacidad = 3 pasajeros, el número máximo de 
  -- caníbales y misioneros en cada orila es de 4
   	
   print "---canibales=4. misioneros=4. Capacidad barca=3---"
   cannibals 4 3

  -- Con una barca de capacidad = 4 se observa que el número máximo de pasos 
  -- con el que se encuentra la solución es (2 * numero caníbales - 3) 
   print "---canibales=5. misioneros=7. Capacidad barca=4---"
   cannibals 5 4

   
   print "---canibales=7. misioneros=7. Capacidad barca=4---"
   cannibals 7 4
