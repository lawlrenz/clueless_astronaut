import sys
import os

infile = sys.argv[1]

if not os.path.exists(infile):
	print '%s does not exist' % infile

def apply_to_level(level, ca):
	new_level = []
	for line in level:
		j = 0
		new_line = []
		for c in line:
			new_line.append(ca(c, j))
			j += 1
		new_level.append(new_line)
	return new_level

# transpose level
level = []
lines = [ x.strip() for x in open(infile) if x.strip() ]
for i in range(len(lines[0])):
	new_line = []
	for line in lines:
		if i < len(line): new_line.append(line[i])
		else: new_line.append('X')
	level.append(new_line)

# prepare container

# prepare dark bottom
level = apply_to_level(level, lambda x, height: '_' if x == ' ' and height > 15 else x)

# apply mapping
mapping = {
	'K': '1 0002',
	'k': '1 0102',
	'!': '1 0003',
	'"': '1 0103',
	'm': '1 0204',
	'X': '1 2902',
	'I': '1 0706',
	'i': '1 0806',
	'L': '2 0707',
	'l': '2 0807',
	'o': '2 0708',
	'p': '2 0808',
	' ': '2 0108',
	'_': '2 0100',
	'E': '2 0100',
	'1': '2 0007',
	'2': '2 0107',
	'3': '2 0207',
	'4': '2 0008',
	'5': '2 0108',
	'6': '2 0208',
	'7': '2 0009',
	'8': '2 0109',
	'9': '2 0209',
	'q': '2 0010',
	'w': '2 0110',
	'W': '2 0110,3 1',
	'e': '2 0210',
	'a': '2 0011',
	'A': '2 0011,3 1',
	's': '2 0111',
	'd': '2 0211',
	'y': '2 0012',
	'x': '2 0112',
	'c': '2 0212',
	'r': '2 0019',
	't': '2 0119',
	'T': '2 0119,3 1',
	'z': '2 0219',
	'f': '2 0020',
	'g': '2 0120',
	'h': '2 0220',
	'v': '2 0021',
	'b': '2 0121',
	'n': '2 0221',
	

	
}

level = apply_to_level(level, lambda x, height: mapping[x])

for line in level:
	print ';'.join(line)

