class Solution(object):
	    def compareVersion(self, version1, version2):
			if version1 == version2:
				return 0;
			v1_parts = version1.split(".");
			v2_parts = version2.split(".");
			if (len(v2_parts)) :
				v2_parts.append("0")
			if (len(v1_parts)) :
				v1_parts.append("0")
			if int(v1_parts[0]) > int(v2_parts[0]):
				return 1;
			elif int(v2_parts[0]) > int(v1_parts[0]):
				return -1;
			else:
				if int(v1_parts[1]) > int(v2_parts[1]):
					return 1;
				elif int(v1_parts[1]) < int(v2_parts[1]):
				    return -1
				return 0;
				
				
