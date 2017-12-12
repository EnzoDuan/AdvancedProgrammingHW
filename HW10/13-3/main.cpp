#include <iostream>
#include <sys/stat.h>

using namespace std;

class copyFile {
    char *pathname1, *pathname2;
public:
    copyFile(char *path1, char *path2) {
        pathname1 = path1;
        pathname2 = path2;
    }
    void copy_file();
    char *set_path();
    void cp_single_simulation();
};

void copyFile::copy_file()
{
    char buffer[100];
    struct stat buffer1;
    struct stat buffer2;
    stat(pathname1, &buffer1);
    stat(pathname2, &buffer2);

    FILE *fp1 = NULL, *fp2 = NULL;
    if ((fp1 = fopen(pathname1, "rb")) == NULL) {
        fprintf(stderr, "Can not open file!\n");
        return;
    }

    if ((fp2 = fopen(pathname2, "wb")) == NULL) {
        fprintf(stderr, "Can not open file!\n");
        return;
    }
    while (!feof(fp1)) {
        fread(&buffer, sizeof(buffer), 1, fp1);
        //		fgets(buffer,BUFFERSIZE, fp1);
        //		fputs(buffer, fp2);
        if ((fwrite(&buffer, sizeof(buffer), 1, fp2) != 1))
            fprintf(stderr, "File write error!\n");
    }
    //Ensure the son has same mode of father
    buffer2.st_mode = buffer1.st_mode;
    fclose(fp1);
    fclose(fp2);
}

//pathname1 is used to extract file/floder name, path2 is used to extract destination path
char * copyFile::set_path() {
    int len1 = strlen(pathname1), rcd = 0, len2 = strlen(pathname2);
    for (int i = len1 - 1; i >= 0; i--) {
        if (pathname1[i] == '/') {
            rcd = i;
            break;
        }
    }
    if (pathname2[len2 - 1] != '/') {
        pathname2[len2] = '/';
        len2++;
    }
    for (int i = len2; pathname1[rcd] != '\0'; i--) {
        pathname2[len2] = pathname1[rcd + 1];
        len2++;
        rcd++;
    }

    return pathname2;
}

void copyFile::cp_single_simulation()
{
    struct stat buffer1;
    struct stat buffer2;
    struct stat buffer_temp;
    char *str_path = pathname2;
    //test source and dest, if they are equal, shut down program
    if (!strcmp(pathname1, pathname2)) {
        fprintf(stderr, "THe two files are equal.\n");
        exit(1);
    }

    stat(pathname1, &buffer1);
    stat(pathname2, &buffer2);
    //To judge whether path1 aim at a folder
    //folder:1   file:0
    if (S_ISDIR(buffer1.st_mode)) {
        //The two are both folders
        if (S_ISDIR(buffer2.st_mode)) {
            set_path();
            //only owner has the whole jurisdiction
            mkdir(pathname2, S_IRWXU);
        }
            //src is folder, dest is not a folder
        else {
            fprintf(stderr, "The destination is not a folder\n");
            return;
        }
    }
    else {
        //src is file, dest is a folder.we need to get the whole path,which includes the src file name
        if (S_ISDIR(buffer2.st_mode)) {
            str_path = set_path();
            copy_file();
        }
        else {
            copy_file();
        }
    }
}

int main(int argc, char **argv) {
    copyFile A(argv[1], argv[2]);
    A.cp_single_simulation();
    return 0;
}