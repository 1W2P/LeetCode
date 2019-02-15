def rindex(lst, val):
    return len(lst) - lst[::-1].index(val) - 1
    
    
def maxArea(height):
    """
    :type height: List[int]
    :rtype: int
    """
    area_max = 0
    h_max = max(height)
    l_h = h_max
        
    while l_h > 0:
        if l_h not in height:
            l_h = l_h - 1
            continue
        
        r_h = l_h
                           
        if height.count(l_h) >= 2:
            y = l_h 
            x = rindex(height, l_h) - height.index(l_h)
	    print('lh, rh : ' + str(y) + ' , lx : ' + str(height.index(l_h)) + ' , rx : ' + str(rindex(height, l_h)))
            if area_max < x*y:
                area_max = x*y

	l_x1 = height.index(r_h)        
	r_x1 = rindex(height, r_h)        

        r_h = r_h - 1
        while r_h > 0:
            y = r_h
            if r_h not in height:
                r_h = r_h - 1
                continue
            else:                      
                l_x2 = height.index(r_h)
                r_x2 = rindex(height, r_h)
		
		if abs(l_x1 - l_x2) > abs(l_x1 - r_x2):
		    lmid = abs(l_x1 - l_x2)
		else:
		    lmid = abs(l_x1 - r_x2)

		if abs(r_x1 - l_x2) > abs(r_x1 - r_x2):
		    rmid = abs(r_x1 - l_x2)
		else:
		    rmid = abs(r_x1 - r_x2)

		if lmid > rmid:
		    x = lmid
		else:
		    x = rmid
		   
		print('lh : ' + str(l_h) + ', rh : ' + str(r_h) + ', {l_x1 : ' + str(l_x1) + ', r_x1 : ' + str(r_x1) + '}' + '{l_x2 : ' + str(l_x2) + ', r_x2 : ' + str(r_x2) + '}'  + ', x : ' + str(x) + ', y:' + str(y) )
		
            if area_max < x*y:
                area_max = x*y
                    
            r_h = r_h - 1
 
	l_h = l_h - 1
              
    print(area_max)
    return area_max


def main():
    height = [8,10,14,0,13,10,9,9,11,11]
    maxArea(height)


main()
