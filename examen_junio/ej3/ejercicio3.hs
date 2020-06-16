------------------------------------------------------------------
--Autor: Diego Marco Beisty, 755232
--Fichero: ejercicio3.hs
--Fecha: 17-06-2020
--Coms: Ejercicio 3, junio 2020.
------------------------------------------------------------------



--------------------------------- (a) ----------------------------------------------------
data Nodo = Fichero String Integer | Directorio String Integer [Nodo] deriving (Show, Eq)
data ArbolDirectorios = Raiz String Integer [Nodo] deriving Show




--------------------------------- FUNCIONES AUXILIARES-------------------------------------------
-- Devuelve tamaño de un nodo
tamNodo :: Nodo -> Integer
tamNodo (Fichero _ t) = t
tamNodo (Directorio _ t _)= t

-- Devuelve nombre de un nodo
nombreNodo :: Nodo -> String
nombreNodo (Fichero n _) = n
nombreNodo (Directorio n _ _) = n

-- Devuelve lista de hijos de un nodo
hijos :: Nodo -> [Nodo]
hijos (Fichero _ _) = []
hijos (Directorio _ _ lista) = lista


--------------------------------- (b) ---------------------------------------------------------
-- Caso recursivo:
-- Si cumple que el nombre del nodo hijo de "nodo" == primer string de la ruta, se reinvoca 
-- con una lista con el nodo hijo y el resto de la ruta. En caso contrario, se reinvoca con 
-- una lista vacía y el resto de la ruta.
-- Casos triviales:
-- Si el primer parámetro es lista vacía, implica que que la ruta no existe, se devuelve 0.
-- Si el primer parámetro es una lista con un nodo y la ruta es una lista vacía, implica que
-- "nodo" es el nodo buscado, se devuelve su tamaño.
statAux :: [Nodo] -> [String] -> Integer
statAux [] _ = 0
statAux [nodo] [] = tamNodo nodo 
statAux [nodo] (x:xs) = statAux [y | y <- (hijos nodo), x == nombreNodo y] xs

--Si ruta es lista vacía, devuelve tamaño de nodo raiz.
--En caso contrario, invoca statAux con una lista con un nodo hijo de la raiz [nodoHijo] 
--si cumple que nombre de nodo hijo == primer String de la lista de Strings. 
--Si no cumple la condición, invoca statAux con lista vacía y el resto de la ruta.
stat :: ArbolDirectorios -> [String] -> Integer
stat (Raiz _ t _ ) [] = t
stat (Raiz _ _ hijos) (x:xs)  = statAux [y | y <- hijos, x == nombreNodo y] xs

------------------------------ (c) -------------------------------------------------------
-- Caso recursivo:
-- Primero cada nodo concatena su nombre con la lista "historial" y devuelve una lista de listas
-- de Strings concatenada con la invocación recursiva a sus nodos hijos.
-- Después concatena el resultado con la listas de listas de Strings de sus nodos hermanos.
-- Caso trivial:
-- La lista de nodos es vacía (no hay hermanos ó no hay hijos), devuelve lista vacía de listas.
findAux :: [Nodo] -> [String]-> [[String]]
findAux [] _ = []
findAux (x:xs) historial = func x ++ (findAux xs historial)
      where
           newHistorial = historial ++ [nombreNodo x]
           func x = [newHistorial] ++ findAux (hijos x) newHistorial

-- Devuelve una lista con todas las rutas posibles de un árbol de directorios.
-- Concatena la ruta del nodo raíz a la lista de rutas de sus nodos hijos
find :: ArbolDirectorios -> [[String]]
find (Raiz _ _ hijos) = [] : (findAux hijos [])


---------------------------------- PRUEBAS -------------------------------------------------
a = Raiz "/" 350 [Directorio "usr" 300 [Directorio "bin" 300 [Fichero "g++" 100, Fichero "vi" 200] ], Directorio "sbin" 50 [Fichero "ghc" 50] ] 
main = do
    print $ find a

    print $ stat a ["sbin", "ghc"]
    print $ stat a ["usr", "bin", "g++"]
    print $ stat a ["usr", "bin", "vi"]
    print $ stat a []
    print $ stat a ["usr"]
    print $ stat a ["var", "share"]

