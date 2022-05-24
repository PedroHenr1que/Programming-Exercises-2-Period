--QUESTÃO 1
converteABC :: Char -> Char
converteABC letter
  | fromEnum(letter) >= 97 && fromEnum(letter) <= 122 = toEnum(fromEnum(letter)-32) :: Char
  | otherwise = letter


--QUESTÃO 2
romanDigit :: Int -> String
romanDigit num
  | num == 1 = "I"
  | num == 2 = "II"
  | num == 3 = "III"
  | num == 4 = "IV"
  | num == 5 = "V"
  | num == 6 = "VI"
  | num == 7 = "VII"
  | num == 8 = "VIII"
  | num == 9 = "IX"
  | num == 10 = "X"
  | otherwise = show(num)


--QUESTÃO 3
digits :: String -> String
digits [] = []
digits (x:xs)
  | check x = [x] ++ digits(xs)
  | otherwise = digits(xs)

check :: Char -> Bool
check x
  | x == '0' = True
  | x == '1' = True
  | x == '2' = True
  | x == '3' = True
  | x == '4' = True
  | x == '5' = True
  | x == '6' = True
  | x == '7' = True
  | x == '8' = True
  | x == '9' = True
  | otherwise = False


--QUESTÃO 4
newReverse :: [Int] -> [Int]
newReverse [] = []
newReverse (x:xs) = newReverse(xs) ++ [x]

