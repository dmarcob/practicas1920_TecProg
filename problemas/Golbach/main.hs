criva primos (x:tail) = criva (primos ++ [x]) ([(i) | i<-tail, (mod i x) /= 0])
criva primos [] = primos

prime :: Int -> [Int]
prime 1 = [1]
prime n = [1] ++ criva [] [2..n]

half :: [(Int, Int)] -> [(Int,Int)]
half list = fst (splitAt(length list `div` 2) list)

goldbach :: Int -> [(Int, Int)]
goldbach n = half [(i,j) | i<- criva [] [2..n], j<-criva [] [2..n], i + j == n]

main = do
	print(prime 44)
	print (goldbach 44)

