/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:11:19 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/24 02:28:51 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int fd1 = open("tect.txt", O_RDWR | O_CREAT, 0666);  // Open file for reading and writing
    if (fd1 == -1)
    {
        perror("this is an error");
        return 1;
    }

    // Write some data to the file
    // write(fd1, "Hello world \n Are you fine  ", 29);

    // Move the file pointer back to the beginning of the file
    //lseek(fd1, 0, SEEK_SET);

    // Read the file content into the buffer
    size_t count;
    char buffer[1024];
    // count = read(fd1, buffer, 5);
    // printf("\n");
    // count = read(fd1, buffer, 5);
    //printf("%lu",count);
    if (count == -1)
    {
        perror("read");
    }
    count = 29;
    for(int i = 0; i < 4;i++)
    {
        // Null-terminate the buffer and print the contents
        buffer[count] = '\0';
        count += read(fd1,buffer,5);  // Ensure the buffer is null-terminated
        printf("%s", buffer);
    }

    // Close the file
    close(fd1);

    return 0;  
    
}
