------------------------------------------------------------------
--Autor: Diego Marco, 755232
--Fichero: BinaryTree.hs
--Fecha: 1-06-2020
--Coms: Practica 6
------------------------------------------------------------------
module BinaryTree where
import Data.List
-----------------------------------------------------------------------------------
---------------------------  PARTE 1  ---------------------------------------------
-----------------------------------------------------------------------------------
--
data Tree t = Empty | Leaf t | Tree t (Tree t) (Tree t)

empty :: Tree x
empty = Empty

leaf :: x -> Tree x
leaf x = Leaf x

tree :: x -> Tree x -> Tree x -> Tree x
tree x lc rc = Tree x lc rc

size :: Tree t -> Integer
size Empty = 0
size (Leaf _) = 1
size (Tree _ lc rc) = 1 + size(lc) + size(rc)


-- Función auxiliar.
-- Dado un árbol t y un valor de indentación n, devuelve una representación del árbol en un String con formato.
-- A razón de un nodo por línea. Contra más alejado de la raíz, más hacia la derecha aparece el nodo.
show' :: Show t => Tree t -> Int -> String
show' (Leaf x) _ = (show x)
show' (Tree x lc rc) n = (show x ) ++ "\n" ++ concat(replicate n " ") ++ "|- " ++ (show' lc (n + 4)) ++ "\n" ++ concat(replicate n " ") ++ "|- " ++ (show' rc (n + 4))
show' Empty _ = show "<>"

-- En la instancia de Tree x se obliga a que el dato de tipo x tenga instanciada la clase Show.
instance Show x => Show (Tree x) where
   show (Leaf x) = (show x)
   show (Tree x lc rc) = show' (Tree x lc rc) 0
   show Empty = show "<>"


-----------------------------------------------------------------------------------
---------------------------  PARTE 2  ---------------------------------------------
-----------------------------------------------------------------------------------

-- Añade el elemento t al arbol Tree t, devolviendo el árbol resultado
add :: Ord t => Tree t -> t -> Tree t
add Empty x = leaf x
add (Leaf x) y
       | y <= x = tree x (leaf y) Empty
       | otherwise = tree x Empty (leaf y)
add (Tree x lc rc) y 
       | y <= x = tree x (add lc y) rc
       | otherwise = tree x lc (add rc y)



build' :: Ord t => [t] -> Tree t
build' (x:[]) = add Empty x
build' (x:tail) = add (build' tail) x

-- Construye un árbol a partir de una lista de elementos de tipo t.
-- Para ello inicialmente voltea la lista e invoca la funcion auxiliar build'
-- para que recursivamente construya el árbol comenzando por el último elemento 
-- de la lisa volteada.
build :: Ord t => [t] -> Tree t
build list = build' (reverse list)




-----------------------------------------------------------------------------------
---------------------------  PARTE 3  ---------------------------------------------
-----------------------------------------------------------------------------------

--Función auxiliar.
--Recibe una lista y devuelve su primera mitad.
primMitad :: [t] -> [t]
primMitad lista = fst(splitAt(length lista `div` 2) lista)

--Función auxiliar.
--Recibe una lista y devuelve su segunda mitad.
segMitad :: [t] -> [t]
segMitad lista = snd(splitAt(length lista `div` 2) lista)

--Función auxiliar.
--Ordena una lista de elementos de tal forma que al ser construidos secuencialmente en un arbol binario
--por la función build, este siempre será un arbol binario equilibrado.
listBalanced :: [t] -> [t]
listBalanced [] = []
listBalanced (x:[]) = [x]
listBalanced list = [head(segMitad list)] ++ listBalanced (primMitad list) ++ listBalanced(tail(segMitad list))

-- Construye un árbol equilibrado a partir de los elementos de una lista
buildBalanced :: Ord t => [t] -> Tree t
buildBalanced list = build(listBalanced (sort list))




-----------------------------------------------------------------------------------
---------------------------  PARTE 4  ---------------------------------------------
-----------------------------------------------------------------------------------

--Recorre un arbol binario en preorden devolviendo la lista correspondiente
preorder :: Tree t -> [t]
preorder Empty = []
preorder (Leaf x) = [x]
preorder (Tree x lc rc) = [x] ++ preorder(lc) ++ preorder(rc)

--Recorre un arbol binario en postorden devolviendo la lista correspondiente
postorder :: Tree t -> [t]
postorder Empty = []
postorder (Leaf x) = [x]
postorder (Tree x lc rc) = postorder(lc) ++ postorder(rc) ++ [x]

--Recorre un arbol binario en indorden devolviendo la lista correspondiente
inorder :: Tree t -> [t]
inorder Empty = []
inorder (Leaf x) = [x]
inorder (Tree x lc rc) = inorder(lc) ++ [x] ++ inorder(rc)

--Construye un arbol equilibrado a partir de un arbol de tipo t
balance :: Ord t => Tree t -> Tree t 
balance Empty = Empty
balance (Leaf x) = Leaf x
balance (Tree x lc rc) = buildBalanced(inorder(Tree x lc rc))



-----------------------------------------------------------------------------------
---------------------------  PARTE 5  ---------------------------------------------
-----------------------------------------------------------------------------------

-- Busca en el árbol t y devuelve una lista con todos los elementos que están entre
-- xmin y xmax (ambos incluidos).
between :: Ord t => Tree t -> t -> t -> [t]
between Empty xmin xmax = []
between (Leaf x) xmin xmax
    | xmax < x = []
    | xmin > x = []
    | otherwise = [x]
between (Tree x lc rc) xmin xmax
    | xmax < x = between lc xmin xmax
    | xmin > x = between rc xmin xmax
    | otherwise = [x] ++ (between lc xmin xmax) ++ (between rc xmin xmax)

