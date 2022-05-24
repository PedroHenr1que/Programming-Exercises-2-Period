-- Questão 1
group :: [[Int]] -> [(Int, Int)]
group [[]] = []
group (x:xs)
  | x /= [] = [ ( (x!!0), elemNum (x!!0) (x:xs) ) ] ++ group(lessEquals (x!!0) (x:xs))
  | otherwise = group xs

elemNum :: Int -> [[Int]] -> Int
elemNum num xs = length( concat [ elemNumAux num ys | ys <- xs] )

elemNumAux :: Int -> [Int] -> [Int]
elemNumAux num ys = [y | y <- ys, y == num]

lessEquals :: Int -> [[Int]] -> [[Int]]
lessEquals num xs = [ lessEqualsAux num ys | ys <- xs]

lessEqualsAux :: Int -> [Int] -> [Int]
lessEqualsAux num ys = [y | y <- ys, y /= num]

-- Questão 2
type Aluno = (String, String, Int, String, Float)

-- A
mediaEnem :: [Aluno] -> Float
mediaEnem list = (sum([ e | (c,n,a,g,e) <- list])) / (fromIntegral $ length list)

-- B  NÃO TA FUNCIONANDO (myMin-não faz sentido)
minMaxIdade :: [Aluno]->(String,Int,String,Int)
minMaxIdade list = concatTuple (myMax list) (myMin list)

concatTuple :: (String,Int) -> (String,Int) -> (String,Int,String,Int)
concatTuple (n1,a1) (n2,a2) = (n1,a1,n2,a2)

myMin :: [Aluno] -> (String,Int)
myMin [(c,n,a,g,e)] = (n,a)
myMin ((c,n,a,g,e):xs)
  | a < snd(myMin xs) = (n,a)
  | otherwise = myMin xs

myMax :: [Aluno] -> (String,Int)
myMax [(c,n,a,g,e)] = (n,a)
myMax ((c,n,a,g,e):xs)
  | a > snd(myMax xs) = (n,a)
  | otherwise = myMax xs

-- C
type Code = String
type Name = String

data Disciplina = Disc Code Name

cadastro :: Disciplina->Aluno->[(String,String,Float)]->[(String,String,Float)]
cadastro (Disc code name) (c,n,a,g,e) xs = xs++[(code,n,e)]