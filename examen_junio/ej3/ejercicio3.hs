------------------------------------------------------------------
--Autor: Diego Marco, 755232
--Fichero: ejercicio3.hs
--Fecha: 17-06-2020
--Coms: Ejercicio 3, junio 2020.
------------------------------------------------------------------
--QUITAR ESTO	
--deriving show, dos veces.
--quitar la a = ..

------------------------------


--------------------------------- (a) ----------------------------------------------------
data Nodo = Fichero String Integer | Directorio String Integer [Nodo] deriving (Show, Eq)
data ArbolDirectorios = Raiz String Integer [Nodo] deriving Show

a = Raiz "/" 350 [Directorio "usr" 300 [Directorio "bin" 300 [Fichero "g++" 100, Fichero "vi" 200] ], Directorio "sbin" 50 [Fichero "ghc" 50] ] 



--------------------------------- (a) ----------------------------------------------------
tamNodo :: Nodo -> Integer
tamNodo (Fichero _ t) = t
tamNodo (Directorio _ t _)= t

nombreNodo :: Nodo -> String
nombreNodo (Fichero n _) = n
nombreNodo (Directorio n _ _) = n

hijos :: Nodo -> [Nodo]
hijos (Fichero _ _) = []
hijos (Directorio _ _ lista) = lista




statAux :: [Nodo] -> [String] -> Integer
statAux [] lista = 0
statAux hermanos [x] = if l == []
                       then 0
                       else tamNodo(head l)
   where
       l = [y | y <- hermanos,  x == nombreNodo y]  
statAux hermanos (x:xs) = if l == []
                          then 0
                          else statAux (hijos $ head l) xs
   where
       l = [y | y <- hermanos, x == nombreNodo y]  

stat :: ArbolDirectorios -> [String] -> Integer
stat (Raiz _ tamanyo _ ) [] = tamanyo
stat (Raiz _ _ hijos) lista  = statAux hijos lista

main = do
    print $ stat a ["usr"]
