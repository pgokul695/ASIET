import pytholog as pl
from time import time
new_kb = pl.KnowledgeBase('Flavor')
new_kb(["likes(noor,sausage)",
	"likes(melissa ,pasta)",
	"likes(dmitry,cookie)",
	"likes(assel, limonade)",
	"food_type(gounda,cheese)",
	"food_type(ritz,cracker)",
	"food_type(steak,meat)",
	"food_type(sausage,meat)",
	"food_type(limonade,juice)",
	"food_type(mojito, juice)",
	"flavor(sweet,dessert)",
	"flavor(savory,meat)",
	"flavor(savory,cjeese)",
	"food_flavor(X,Y) :- food_types(X,Z),flavour(Y,Z)",
	"dish)to_like(X,Y) :- likes(X,L),food_type(L,T), food_flavor(Y,F),neq(L,Y)"])

print(new_kb.query(pl.Expr("likes(noor,sausage)")))
start = time()
print(new_kb.query(pl.Expr("food_flavor(What,sweet)")))
print(time() - start)
