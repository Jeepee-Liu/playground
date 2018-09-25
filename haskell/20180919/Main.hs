-- Data type of a binary tree of integer values
data Tree = Null | Node Tree Int Tree
    deriving Show

{- Tree like this:
         11
        /  \
     21      22
    /  \    /  \
  31   32 33    34
-}
tree = Node (Node (Node Null 31 Null) 21 (Node Null 32 Null)) 11 (Node (Node Null 33 Null) 22 (Node Null 34 Null))

inOrderTraversal :: Tree -> [Int]
inOrderTraversal Null = []
inOrderTraversal tree@(Node lChild x rChild)
    = inOrderTraversal lChild ++ [x] ++ inOrderTraversal rChild

preOrderTraversal :: Tree -> [Int]
preOrderTraversal Null = []
preOrderTraversal tree@(Node lChild x rChild)
    = x : preOrderTraversal lChild ++ preOrderTraversal rChild

postOrderTraversal :: Tree -> [Int]
postOrderTraversal Null = []
postOrderTraversal tree@(Node lChild x rChild)
    = postOrderTraversal lChild ++ postOrderTraversal rChild ++ [x]

-- inOrderTraversalNR :: Tree -> [Int]
-- inOrderTraversalNR Null = []
-- inOrderTraversalNR tree = do
--     let xs = [tree]
--     return xs

--------- My List data type:

data List t = E
            | C t (List t)
    deriving Show

list1 :: List Int
list1 = C 1 (C 2 (C 3 (C 4 (C 5 E))))

list2 :: List Char
list2 = C 'a' (C 'b' (C 'c' (C 'd' E)))

list3 :: List Bool
list3 = C True (C True (C False E))

mapList :: (a -> b) -> List a -> List b
mapList _ E = E
mapList f (C x xs) = C (f x) (mapList f xs)

filterList :: (t -> Bool) -> List t -> List t
filterList _ E = E
filterList p (C x xs)
                | p x = C x (filterList p xs)
                | otherwise = filterList p xs

reduceList :: (b -> a -> b) -> b -> List a -> b
reduceList _ y E = y
reduceList f y (C x xs) = reduceList f (f y x) xs


-- IsSquare
square :: (Integral a) => a -> Bool
square n = foldr (\x y -> y || x == True) False [x^2 == n | x<-[1..n]]

divisors :: Int -> [Int]
divisors x = filter p [1..x]
    where p y = (x `mod` y) == 0

main :: IO()
main = do
    print tree
    print $ preOrderTraversal tree
    print $ inOrderTraversal tree
    print $ postOrderTraversal tree
    print $ mapList (*3) list1
    print $ filterList odd list1
    print $ reduceList (+) 0 list1
    print $ square 2501
    print $ divisors 42
