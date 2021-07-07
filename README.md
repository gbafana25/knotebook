# knotebook

Program that will be used to store throwaway-code for kata exercises/ideas.

## Usage

With curl:
	- `curl -X POST --data 'name=[program_name]&lang=[language]' --data 'code="'"$(cat [filename.*])"'"' localhost:1234/create`

## Tasks
- [x] async server base
- [x] parser that can parse url-format variables, get correct parameters and code
- [ ] store data in binary form
