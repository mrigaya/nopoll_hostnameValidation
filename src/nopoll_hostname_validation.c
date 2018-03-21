
#include <nopoll_hostname_validation.h>

static noPollHostValidationStatus nopoll_cert_common_name_host_check(const X509 *server_cert, const char *hostname);
static noPollHostValidationStatus nopoll_cert_subject_alt_name_host_check(const X509 *server_cert, const char *hostname);

/**
* Tries to find a match for hostname in the certificate's Common Name field.
*
* Returns MATCH_FOUND if a match was found.
* Returns MATCH_NOT_FOUND if no matches were found.
* Returns MAL_FORMED_CERTIFICATE if any of the hostnames had a NUL character embedded in it.
* Returns ERROR if there was an error.
*/
static noPollHostValidationStatus nopoll_cert_common_name_host_check(const X509 *server_cert, const char *hostname) 
{
	//TODO
	/** Get the CN field data from the certificate
	* if everything is fine validate hostname against available data */

	// common_name_data : Will have patterns present in certificate

	/* Compare expected hostname with the CN*/
    if (nopoll_match_hostname(common_name_data, hostname)) {
            return MATCH_FOUND;
    }
    else {
            return MATCH_NOT_FOUND;
    }

}


/**
* Tries to find a match for hostname in the certificate's Subject Alternative Name extension field.
*
* Returns MATCH_FOUND if a match was found.
* Returns MATCH_NOT_FOUND if no matches were found.
* Returns MAL_FORMED_CERTIFICATE if any of the hostnames had a NUL character embedded in it.
* Returns NO_SAN_PRESENT if the SAN extension was not present in the certificate.
*/
static noPollHostValidationStatus nopoll_cert_subject_alt_name_host_check(const X509 *server_cert, const char *hostname)
{
	//TODO
}


/**
* Validates the server's identity by looking for the expected hostname in the
* server's certificate. As described in RFC 6125, it first tries to find a match
* in the Subject Alternative Name extension. If the extension is not present in
* the certificate, it checks the Common Name instead.
*
* Returns MATCH_FOUND if a match was found.
* Returns MATCH_NOT_FOUND if no matches were found.
* Returns MAL_FORMED_CERTIFICATE if any of the hostnames had a NUL character embedded in it.
* Returns ERROR if there was an error.
*/

noPollHostValidationStatus nopoll_validate_hostname(const X509 *server_cert, const char *hostname) {
	noPollHostValidationStatus result;

	if((server_cert == NULL) || (hostname == NULL))
		return Error;

	/* First try the Subject Alternative Names extension*/
	result = nopoll_cert_subject_alt_name_host_check(server_cert, hostname);
	if (result == NO_SAN_PRESENT) {
		/* Extension was not found: try the Common Name*/
		result = nopoll_cert_common_name_host_check(server_cert, hostname);
	}

	return result;
}
