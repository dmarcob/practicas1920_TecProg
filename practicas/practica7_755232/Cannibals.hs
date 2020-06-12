------------------------------------------------------------------
--Autor: Diego Marco, 755232
--Fichero: Cannibals.hs
--Fecha: 1-06-2020
--Coms: Solución adaptada de: https://sudonull.com/post/145971-Solving-the-Haskell-Missionary-and-Cannibal-Problem
------------------------------------------------------------------

module Cannibals where
import Data.List

-- Primero necesitamos representar la estructura de datos del juego.
-- Un dato de tipo Char nos indica si el barco está  en la orilla derecha 'R'
-- o en la orilla izquierda 'L'.
-- El primer dato entero representa el número de misioneros que hay en una orilla designada por el 
-- dato de tipo Char. Siendo n menos los misioneros de esa orilla el número de misioneros que hay 
-- en la orilla opuesta.
-- El segundo dato entero representa el número de caníbales que hay en la orilla indicada por el tipo Char.
-- Siendo el número de caníbales que hay en la orilla opuesta n menos el número  de caníbales en la orilla designada
-- por el dato de tipo char.
data Board = MakeBoard Int Int Char deriving (Show,Eq)

-- Función copiada de: https://sudonull.com/post/145971-Solving-the-Haskell-Missionary-and-Cannibal-Problem
-- Mueve el barco de una orilla a la opuesta
-- 'L' indica orilla izquierda
-- 'R' indica orilla derecha
oppositeBank :: Char -> Char
oppositeBank bank
        | bank == 'L' = 'R'
        | otherwise = 'L'


-- Función propia.
-- Devuelve una lista de tuplas que indican todos los movimientos posibles con una
-- barca de capacidad m.
-- El primer entero de una tupla devuelta indica el número de misioneros que se mueven 
-- y el segundo entero de una tupla indica el número de caníbales que se mueven.
-- Por ejemplo: Una barca de capacidad m=2 tendrá los movimientos posibles: [(0,2),(2,0),(1,1),(0,1),(1,0)]
allmoves :: Int -> [(Int, Int)]
allmoves 1 = [(0,1),(1,0)]
allmoves m = [(x,y) | x <- [0..m], y <-[0..m], x + y == m] ++ allmoves (m - 1)

-- Función propia.
-- Genera una lista con todos los  posibles tableros con "n" misioneros/caníbales y una capacidad "m" de la barca
moves :: Board -> Int -> Int -> [Board]
moves (MakeBoard msn cnb bk) n m = [MakeBoard (n - msn + fst(y)) (n - cnb + snd(y)) (oppositeBank bk) | y <- allmoves m]  

-- Función adaptada de : https://sudonull.com/post/145971-Solving-the-Haskell-Missionary-and-Cannibal-Problem
-- Devuelve True si el tablero es válido, False en caso contrario.
-- Se considera un tablero válido si el número de caníbales y misioneros pertenece al rango [0,n]
-- Además tiene que cumplir que en cada orilla el el número de caníbales nunca es superior al de misioneros
-- si hay algún misionero en esa orilla.
validBoard :: Int -> Board -> Bool
validBoard n (MakeBoard msn cnb bk) = if msn >= 0 && msn <= n && cnb >= 0 && cnb <= n 
                                       then  not(((cnb > msn) && (msn>0)) || ((n - cnb > n - msn) && (n - msn > 0)))
                                       else False


-- Función adaptada de: https://sudonull.com/post/145971-Solving-the-Haskell-Missionary-and-Cannibal-Problem
-- Se recibe un entero "n" indicando el número de misioneros/caníbales y un entero "m" indicando la capacidad de la barca.
-- Además recibe una lista de listas de tableros en la que a cada lista de tableros se irá añadiendo todos sus posibles tableros
-- resultantes de realizar todos los movimientos válidos a partir de ese tablero.
--
-- Caso trivial:
-- Si el primer tablero de la primera lista de listas indica qie los n caníbales y misioneros están en la
-- orilla derecha, la función termina.
--
-- Caso recursivo:
-- Se realiza una búsqueda primero en anchura en la que se van generando y añadiendo todos los posibles tableros a las listas
-- de tableros a partir del primer tablero de cada lista.
--
-- Ejemplo. Tres misioneros y caníbales. Capacidad barca de 2.
-- bfsSolution 3 2 [[MakeBoard 3 3 'L']]
-- 	Invocación 1 	[[MakeBoard 3 3 'L']]
-- 	Invocación 2	[[MakeBoard 0 2 'R'], [MakeBoard 1 1 'R'],  [MakeBoard 0 1 'R']]
-- 	............
-- 	Invocación x	[[MakeBoard 0 2 'L', ..], ..] 
bfsSolution :: Int -> Int -> [[Board]] -> [Board]
bfsSolution n m (path:tail')
        | elem (MakeBoard n n 'R') extensions = MakeBoard n n 'R' : path
        | otherwise = bfsSolution  n m (tail' ++ [ext : path | ext <- extensions, not(elem ext path)])
        where
                headState  = head path
                extensions = filter (validBoard n) (moves headState n m)

-- Imprime por pantalla el camino para llegar desde el tablero inicial con todos los caníbales/misioneros en la orilla izquierda
-- hasta el tablero final con todos los caníbales/misioneros en la orilla derecha
cannibals :: Int -> Int ->IO()
cannibals n m =  mapM_ (putStrLn . show) $ (reverse . bfsSolution n m) ([[MakeBoard n n 'L']])
