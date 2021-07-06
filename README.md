# knotebook

Program that will be used to store throwaway-code for kata exercises/ideas.

## Usage

With curl:
	- create a file with the format: `name=[name]&lang=[language]&code=`
	- add the code in with: `cat >> [filename.txt]`
	- run curl `curl -X POST -d '@[filename.txt]' localhost:1234/create`

## Tasks
- [x] async server base
- [x] parser that can parse url-format variables 
- [ ] store data in binary form
