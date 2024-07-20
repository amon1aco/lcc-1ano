-- Teste 2021

--1
bb :: Eq a => [a] -> [a] -> [a]
bb [] _ = []
bb l [] = l
bb (a:b) (c:d) = bb (delete c (a:b)) d

delete :: Eq a => a -> [a] -> [a]
delete a [] = []
delete a (b:c) | a == b = c
               | otherwise = b : delete a c

--2
type MSet a = [(a,Int)]

--a
removemset :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removemset x [] = []
removemset x ((a,b):c) | x == a = c
                       | otherwise = (a,b) : removemset x c

--b
--calcula :: MSet a -> ([a],Int)
--calcula ((a,b):c) = map ei (a,b) c

--ei :: [(a,Int)] -> [([a],Int)]
--ei [] = []
--ei ((a,b):c) = ((a:d),(b+e))
--       where (d,e) = ei c

    -- Funções de ordem superior ta foda!!
   -- A mim parece me que isto aqui será um map, mas esta complicado, fica para o final.

--3
--partes :: String -> Char -> [String] 
partes [] _ = []
partes (a:b) x | a == x = ", " ++ partes b x
               | otherwise = [a] ++ partes b x

   -- ns, so se usar uma auxiliar pra quebrar outra pra escrever, ta foda

--4
data BTree a = Empty | Node a (BTree a) (BTree a)
 --  deriving Show  

a1 = Node 5 (Node 3 Empty Empty)
            (Node 7 Empty (Node 9 Empty Empty))

--a
remove :: Ord a => a -> BTree a -> BTree a 
remove a (Empty) = Empty
remove a (Node x e d) | a > x = Node x e (remove a d)
                      | a < x = Node x (remove a e) d 
                      | a == x = Empty 

--b
instance Show (BTree a) where
   --show (Node a e d) = show e ++ "<-" ++ show a ++ "->" ++ show d 
   show Empty = show "*"

   -- provavelmente i should kms :(((

--4
sorton :: Ord b => (a -> b) -> [a] -> [a]
sorton f [] = []
--sorton f (a:b) = ajuda (f a) (sorton f b)
--sorton f (a:b) = foldr (ajuda (f a)) [] (a:b)

ajuda :: Ord a => a -> [a] -> [a]
ajuda x [] = [x]
ajuda x (a:b) | x > a = a : ajuda x b
              | otherwise = x : a : b 

   -- PQP

--5
data FileSystem = File Nome | Dir Nome [FileSystem]
   deriving Show 

type Nome = String 

fs = Dir "usb" [Dir "xxx" [File "abc.txt", File "readme", Dir "PF" [File "exemplo.hs"]],
                 Dir "yyy" [], Dir "zzz" [Dir "tmp" []], File "teste.c"]

--a
fichs :: FileSystem -> [Nome] 
fichs (File a) = [a]
--fichs (Dir a l) = 
   
  -- this shit is hard...

--b

--c

      -- mas q grande teste de merda!