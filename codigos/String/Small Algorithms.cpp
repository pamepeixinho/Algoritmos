Algoritmos úteis para classificaçao de strings:
	(1) isAnagram
	(2) isPalindrome

(1)
int isAnagram(string str1, string str2){
    int num1[26] = {0}, num2[26] = {0}, i = 0;
 
    while (str1[i] != '\0'){
        num1[str1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (str2[i] != '\0'){
        num2[str2[i] -'a']++;
        i++;
    }
    for (i = 0; i < 26; i++){
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
}

(2)
int isPalindrome(string str){
	
	for(int i = 0; i < str.size()/2; i++){
		if(str[i] != str[str.size() - 1 - i])
			return 0;
	}
	return 1;
}
