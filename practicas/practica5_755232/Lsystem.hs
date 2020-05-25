------------------------------------------------------------------
--Autor: Diego Marco, 755232
--Fichero: Lsystem.hs
--Fecha: 25-05-2020
--Coms: Parte 2 practica5. Sistemas de Lindemayer. Funcion lsystem
------------------------------------------------------------------
module Lsystem where

lsystem :: (Char -> String) -> String -> Int -> String

--Fin de la recursion
lsystem rules axioma 0 = axioma

-- Mapea para cada caracter del axioma su regla correspondiente 
-- y se reinvoca con nVeces - 1
lsystem rules axioma nVeces =
      lsystem rules str (nVeces-1)
      where
        str =  concat(map rules axioma)

