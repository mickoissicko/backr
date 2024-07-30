#include <curl/curl.h>
#include <curl/easy.h>
#include <stdlib.h>
#include <stdio.h>

// dont change
size_t WriteData(
    void* ptr,
    size_t size,
    size_t nmemb,
    void* stream
){
    size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
    return written;
}

void Get(const char FILENAME[], const char URL[])
{
    CURL* Handle;
    Handle = curl_easy_init();

    FILE* Script;

    if (Handle)
    {
            Script = fopen(FILENAME, "wb");

            if (Script == NULL)
            {
                printf("error (file)\n");
                exit(1);
            }

        curl_easy_setopt(Handle, CURLOPT_URL, URL);
        curl_easy_setopt(Handle, CURLOPT_WRITEFUNCTION, WriteData);
        curl_easy_setopt(Handle, CURLOPT_WRITEDATA, Script);

        CURLcode CurlCode;
        CurlCode = curl_easy_perform(Handle);

        if (CurlCode != CURLE_OK)
            perror("error (downloading)\n");

        curl_easy_cleanup(Handle);
        fclose(Script);
    }

    else
    {
        perror("error (init)\n");
        exit(1);
    }
}

