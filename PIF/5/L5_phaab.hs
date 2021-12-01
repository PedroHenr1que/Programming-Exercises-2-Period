-- Questão 1
twice :: (Int -> Int) -> Int -> Int
twice func num = func (func num) 

-- Questão 2
filterFirst :: (a->Bool) -> [a] -> [a]
filterFirst func [] = []
filterFirst func (x:xs)
  | func x = x : filterFirst func xs
  | otherwise = xs

-- Questão 3
switchMap :: (a -> a) -> (a -> a) -> [a] -> [a]
switchMap f1 f2 [] = []
switchMap f1 f2 [a] = [f1 a]
switchMap f1 f2 (n1:n2:tail) = (f1 n1) : (f2 n2) : switchMap f1 f2 tail