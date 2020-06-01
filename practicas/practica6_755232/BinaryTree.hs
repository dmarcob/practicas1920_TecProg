------------------------------------------------------------------
--Autor: Diego Marco, 755232
--Fichero: BinaryTree.hs
--Fecha: 1-06-2020
--Coms: Practica 6
------------------------------------------------------------------
-- module BinaryTree where



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

-- Funcion auxiliar que obtiene la altura de un árbol binario
altura :: Tree t -> Int
altura Empty = 0
altura (Leaf _) = 0
altura (Tree _ lc rc) = 1 + max (altura lc) (altura rc)

-- Indentacion para imprimir el arbol (a más altura más identacion de linea)
indentado (Tree x lc rc) = concat(replicate(altura(Tree x lc rc) * 3) " ")

-- En la instancia de Tree x se obliga a que el dato de tipo x tenga instanciada la clase Show.
instance Show x => Show (Tree x) where
   show (Leaf x) = (show x)
   show (Tree x lc rc) = indentado(Tree x lc rc) ++ (show x) ++ "\n" ++ indentado(Tree x lc rc) ++ "|- " ++ (show lc) ++ "\n" ++ indentado(Tree x lc rc)  ++ "|- " ++  (show rc)
   show Empty = show "<>"


tree0 = tree "R" (tree "HI" (leaf "NII") (leaf "NID")) (tree "HD" (leaf "NDI") (leaf "NDD"))


main = do
   print tree0
