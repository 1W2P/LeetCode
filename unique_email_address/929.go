func numUniqueEmails(emails []string) int {
    emailToSend := make(map[string]bool)
    for _, email := range emails {
        actualEmail := []rune{}
        isDomainPart := false
        ignore := false
        for _, c := range email {
            if !isDomainPart {
                if c == '.' {
                    continue
                } else if c == '+' {
                    ignore = true
                    continue
                }
            }
            if c == '@' {
                isDomainPart = true
                ignore = false
            }
            
            if !ignore {
                actualEmail = append(actualEmail, c)
            }
        }
        emailToSend[string(actualEmail)] = true
    }
    return len(emailToSend)
}