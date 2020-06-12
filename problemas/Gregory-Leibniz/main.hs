gregoryleibniz :: [Float]
gregoryleibniz = [((-1)**x)/(2*x + 1) | x <-[0..]]


sumPi :: Int -> Float
sumPi n = 4 * (sum $ take n gregoryleibniz)

main =  do
	print $ sumPi 1000000
