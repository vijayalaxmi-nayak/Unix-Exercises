#! /bin/bash

#Exercise 1 - qyou.log
#create a new file called failed_status.txt which stores the return status of all failed API calls.
grep "status_code [45]" qyou.log | cut -d " " -f 16  |tee  failed_status.txt

#create a new file called failed_api_calls.txt which stores the URLs for all non successful API calls. 
grep "status_code [45]" qyou.log | cut -d " " -f 7  | tee failed_api_calls.txt

#Building upon the output file obtained from (2), store the request path parameters of the HTTP request in another file called failed_parameters.txt
cut -d "?" -f 2 < failed_api_calls.txt  | tee failed_parameters.txt


#Exercise 2 - sidekiq.log 
#Extract all the Media Ids which have not been found in the log sample.
grep "RuntimeError: Media [0-9]* not found" sidekiq.log | cut -d " " -f 6,7 | tee MediaId.txt

#Print the output sorted by the Media Ids, without duplicates
sort -u -n -k 2 < MediaId.txt | tee SortMediaId.txt

