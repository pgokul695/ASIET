import pytholog as pl
from sympy import *
rain = Symbol("Rain")
hagrid = Symbol("hagrid")
dumbledore = Symbol("dumbeldore")
logical_sentance = And(rain,hagrid)
print(logical_sentance)
print(logical_sentance.subs({rain: True,hagrid: False}))
print(satisfiable(logical_sentance))

implication_logic = Implies(Not(rain),hagrid)
print(implication_logic)
print(satisfiable(implication_logic))
knowledge_base = And(
	Implies(Not(rain),hagrid),
	Or(hagrid,dumbledore),
	Not(And(hagrid,dumbledore)),
	hagrid
	)
print(knowledge_base)
models = satisfiable(knowledge_base,all_models=True)
for model in models:
	print(model)
