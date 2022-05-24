-- QUESTÃO 1
elemNum :: Int -> [Int] -> Int
elemNum x [] = 0
elemNum x (y:ys)
  | x == y = 1 + elemNum x ys
  | otherwise = elemNum x ys



-- QUESTÃO 2
elemNum_2 :: Int -> [Int] -> Int
elemNum_2 y xs = length([x | x <- xs, x == y])



-- QUESTÃO 3
unique :: [Int] -> [Int]
unique [] = []
unique (x:xs)
  | (elemNum x xs) == 0 = [x] ++ unique xs
  | otherwise = unique( lessEquals x xs )


lessEquals :: Int -> [Int] -> [Int]
lessEquals x [] = []
lessEquals x (y:ys)
  | x == y = lessEquals x ys
  | otherwise = [y] ++ lessEquals x ys



-- QUESTÃO 4
unique_2 :: [Int] -> [Int]
unique_2 xs = [x | x <- xs, (elemNum_2 x xs) == 1]



-- QUESTÃO 5
orderTriple :: (Int,Int,Int) -> (Int,Int,Int)
orderTriple x = (smallest x, mid x, biggest x)

mid :: (Int, Int, Int) -> Int
mid (x, y, z)
  | x < y && x > z = x
  | y > x && y < z = y
  | otherwise = z

biggest :: (Int, Int, Int) ->Int
biggest (x, y, z)
  | x > y && x > z = x
  | y > z && y > x = y
  | otherwise = z

smallest :: (Int, Int, Int) ->Int
smallest (x, y, z)
  | x < y && x < z = x
  | y < z && y < x = y
  | otherwise = z