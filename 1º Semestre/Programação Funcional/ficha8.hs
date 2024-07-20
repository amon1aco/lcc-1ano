-- Ficha 8

import Data.List
import Data.Char 


--1
data Frac = F Integer Integer 
       -- deriving Show

--a
mdc :: Integer -> Integer -> Integer 
mdc a b = last [n | n <- [1..(min a b)], mod a n == 0, mod b n == 0]

normaliza :: Frac -> Frac
normaliza (F x y) | mdc x y == 1 = (F x y)
                  | otherwise = (F (div x z)(div y z))
         where z = mdc x y

--b
instance Eq Frac where
        (F a b) == (F c d) = a*d == b*c

--c
instance Ord Frac where
        (F a b) <= (F c d) = a*d <= b*d

--d
instance Show Frac where
        show (F a b) = show a ++ "/" ++ show b

--e
instance Num Frac where
     --   class (Eq a,Show a) => Num a where
     --   (+) (*) (-) :: a -> a -> a
     --   negate, abs, signum :: a -> a
     --   fromInteger :: Integer -> a

     (F a b) + (F c d) = normaliza (F (a*d + c*b) (b*d))
     (F a b) * (F c d) = normaliza (F (a*c) (b*d))
     (F a b) - (F c d) = normaliza (F (a*d - c*b) (b*d))
     negate (F a b) = (F (-a) b)
     abs (F a b) | a > 0 && b > 0 = (F a b)
                 | a < 0 && b < 0 = (F a b)
                 | a > 0 && b < 0 = (F a (-b))
                 | a < 0 && b > 0 = (F (-a) b)
     signum (F a b) | a * b > 0 = 1
                    | a == 0 = 0
                    | a * b < 0 = -1
     fromInteger x = (F x 1)

--f
tl :: Frac -> [Frac] -> [Frac]
tl (F a b) [] = []
tl (F a b) ((F x z):y) | (F (2*a) b) > (F x z) = (F x z) : tl (F a b) y
                       | otherwise = tl (F a b) y
        -- não tenho a certeza se está a funcionar a 100%

--3

data Movimento = Credito Float | Debito Float 
data Data = D Int Int Int deriving Eq
data Extrato = Ext Float [(Data, String, Movimento)]
        
ext = Ext 100 [(D 8 12 21, "Fui às moças", Debito 20),(D 1 1 22, "Taremi", Credito 100)]

--a
instance Ord Data where
     compare (D a b c) (D x y z) | c < z || c == z && b < y || c == z && b == y && a < c = GT 
                                 | c == z && b == y && a == x = EQ
                                 | otherwise = LT

--b
instance Show Data where
        show (D a b c) = show a ++ "/" ++ show b ++ "/" ++ show c

--c
ordena :: Extrato -> Extrato 
ordena (Ext a l) = Ext a (sortBy (\(data1,_,_)(data2,_,_) -> compare data1 data2) l )
        -- Não sei fazer :(
        -- pelos visots o sortBy com o compare funcionam de forma a ordenar listas

--d
instance Show Extrato where
        show (Ext a l) = "Saldo Anterior: " ++ show a ++
                         "\n---------------------------------------------------" ++
                         "\nData        Descrição      Credito        Debito" ++
                         "\n---------------------------------------------------\n" ++ 
                         concatMap (\(dat,str,_)-> show dat ++ "                 " ++ map toUpper str ++ "    \n") l ++
                         "-----------------------------------------------------" ++
                         "\nSaldo Atual: " ++ show (saldo (Ext a l))

saldo :: Extrato -> Float
saldo (Ext x lm) = foldl (\acc (_,_,mov) -> case mov of Credito n -> acc + n
                                                        Debito n -> acc - n) x lm

                -- Não esta a funcionar a 100% por causa da linha 88 e 89 mas está la perto, essas linhas também não fui eu que fiz nem a função saldo