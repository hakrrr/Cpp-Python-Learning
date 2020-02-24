#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOR(from, to) for(int from = 0; from < to; ++from)
#define FORR(from, end) for(int from = end; from >= 0; --from)

#pragma warning(disable : 4996)

void swap(char** i, char** j) {
	char* local = *i;
	*i = *j;
	*j = local;
}

void reverse(int start, int end, char** ptr) {
	FOR(i, (end + 1 - start) / 2)
		swap(ptr + start + i, ptr + end - i);
}

int next_permutation(int n, char** s)
{

	int k = -1, l = -1;
	//Step 1: Find largest k s[k] < s[k+1]
	FORR(i, n - 2) {
		if (strcmp(s[i], s[i + 1]) < 0) {
			k = i;
			break;
		}
	}

	if (k == -1)
		return 0;

	//Step 2: Find largest l s[k] < s[l]
	FORR(i, n - 1) {
		if (strcmp(s[k], s[i]) < 0) {
			l = i;
			break;
		}
	}
	
	//Step 3: Swap k and l
	swap(s + k, s + l);

	//Step 4: Reverse from k + 1 till n
	reverse(k + 1, n - 1, s);
	
	return 1;
}

//char**** get_document(char* text) {
//	char**** result;
//	int p = 0, s = 0, w = 0, l = 0;
//
//	result = (char****)malloc(sizeof(char***) * 1024);
//	result[p] = (char***)malloc(sizeof(char**) * 1024);
//	result[p][s] = (char**)malloc(sizeof(char*) * 1024);
//	result[p][s][w] = (char*)malloc(sizeof(char) * 1024);
//
//	for (int i = 0; text[i] != '\0'; ++i) {
//		switch (text[i]) {
//			case ' ':
//				result[p][s][w] = (char*)realloc(result[p][s][w], sizeof(char) * l);
//				++w;
//				l = 0;
//				result[p][s][w] = (char*)malloc(sizeof(char) * 1024);
//				break;
//			case '.':
//				result[p][s][w] = (char*)realloc(result[p][s][w], sizeof(char) * l);
//				++w;
//				result[p][s] = (char**)realloc(result[p][s], sizeof(char*) * w);
//				++s;
//				l = 0;
//				w = 0;
//				result[p][s] = (char**)malloc(sizeof(char*) * 1024);
//				result[p][s][w] = (char*)malloc(sizeof(char) * 1024);
//				break;
//			case '\n':
//				result[p][s][w] = (char*)realloc(result[p][s][w], sizeof(char) * l);
//				++w;
//				result[p][s] = (char**)realloc(result[p][s], sizeof(char*) * w);
//				++s;
//				result[p] = (char***)realloc(result[p], sizeof(char**) * s);
//				++p;
//				l = 0;
//				w = 0;
//				s = 0;
//				result[p] = (char***)malloc(sizeof(char**) * 1024);
//				result[p][s] = (char**)malloc(sizeof(char*) * 1024);
//				result[p][s][w] = (char*)malloc(sizeof(char) * 1024);
//				break;
//
//			default: 
//				result[p][s][w][l] = text[i];
//				++l;
//		}
//	}
//	return result;
//}

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;


void print_all_packages(town t) {
	printf("%s:\n", t.name);
	FOR(i, t.offices_count) {
		printf("\t%d:\n", i);
		FOR(j, t.offices[i].packages_count) {
			printf("\t\t%s\n", t.offices[i].packages[j].id);
		}
	}
}

void send_all_acceptable_packages(town* source, int source_office_index, 
	town* target, int target_office_index) {
	int sourceSize = source->offices[source_office_index].packages_count;
	int targetSize = target->offices[target_office_index].packages_count;

	package* local = (package*)malloc(sizeof(package) * sourceSize);
	int localSize = 0;

	FOR(i, sourceSize) {
		package sourceP = source->offices[source_office_index].packages[i];
		post_office targetPost = target->offices[target_office_index];
		
		//if (constraint)
		if (targetPost.min_weight <= sourceP.weight && sourceP.weight <= targetPost.max_weight) {
			target->offices[target_office_index].packages = (package*)
				realloc(target->offices[target_office_index].packages, sizeof(package) * ++targetSize);
			target->offices[target_office_index].packages[targetSize - 1] = sourceP;
		}
		else {
			local[localSize++] = sourceP;
		}
	}
	//Set old source to local pointer
	local = (package*)realloc(local, sizeof(package) * (localSize));
	free(source->offices[source_office_index].packages);
	source->offices[source_office_index].packages = local;
	//Update source & target packagecounts
	source->offices[source_office_index].packages_count = localSize;
	target->offices[target_office_index].packages_count = targetSize;

}

town town_with_most_packages(town* towns, int towns_count) {
	town res;
	int maxCount = INT_MIN;
	FOR(i, towns_count) {
		int count = 0;
		FOR(j, towns[i].offices_count) {
			count += towns[i].offices[j].packages_count;
		}

		if (count > maxCount) {
			maxCount = count;
			res = towns[i];
		}
	}

	return res;
}

town* find_town(town* towns, int towns_count, char* name) {
	FOR(i, towns_count)
		if (strcmp(name, towns[i].name) == 0)
			return towns+i;

	return NULL;
}

//int main()
//{
//	int towns_count;
//	scanf("%d", &towns_count);
//	town* towns = (town*) malloc(sizeof(town) * towns_count);
//	for (int i = 0; i < towns_count; i++) {
//		towns[i].name = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
//		scanf("%s", towns[i].name);
//		scanf("%d", &towns[i].offices_count);
//		towns[i].offices = (post_office*) malloc(sizeof(post_office) * towns[i].offices_count);
//		for (int j = 0; j < towns[i].offices_count; j++) {
//			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
//			towns[i].offices[j].packages = (package*) malloc(sizeof(package) * towns[i].offices[j].packages_count);
//			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
//				towns[i].offices[j].packages[k].id = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
//				scanf("%s", towns[i].offices[j].packages[k].id);
//				scanf("%d", &towns[i].offices[j].packages[k].weight);
//			}
//		}
//	}
//	int queries;
//	scanf("%d", &queries);
//	char town_name[MAX_STRING_LENGTH];
//	while (queries--) {
//		int type;
//		scanf("%d", &type);
//		switch (type) {
//		case 1:
//			scanf("%s", town_name);
//			town* t = find_town(towns, towns_count, town_name);
//			print_all_packages(*t);
//			break;
//		case 2:
//			scanf("%s", town_name);
//			town* source = find_town(towns, towns_count, town_name);
//			int source_index;
//			scanf("%d", &source_index);
//			scanf("%s", town_name);
//			town* target = find_town(towns, towns_count, town_name);
//			int target_index;
//			scanf("%d", &target_index);
//			send_all_acceptable_packages(source, source_index, target, target_index);
//			break;
//		case 3:
//			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
//			break;
//		}
//	}
//	return 0;
//}
