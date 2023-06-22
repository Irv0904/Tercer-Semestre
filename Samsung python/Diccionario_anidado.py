import copy

school={
'kim':{'age':16,'hei':170,'grade':3},
'lee':{'age':15,'hei':168,'grade':2},
'choi':{'age':14,'hei':173,'grade':1}
}
school2 = copy.deepcopy(school)
print(school)
print(school2)

x=school is  school2
print(x)