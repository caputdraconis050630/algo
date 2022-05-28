grade_dic = {
	'A+':4.5, 
	'A0':4.0,
	'B+':3.5,
	'B0':3.0,
	'C+':2.5,
	'C0':2.0,
	'D+':1.5,
	'D0':1.0,
	'F':0.0
}

ans = 0.0
sub = 0.0

for i in range(20):
	sub_name, sub_score, sub_grade = input().split()
	if sub_grade == 'P':
		continue
	else:
		ans += (float(sub_score) * grade_dic[sub_grade])
		sub += float(sub_score)

print(ans/sub)
