# Onboarding Screens with Jetpack Compose

This project demonstrates how to create onboarding screens in Jetpack Compose using horizontal paging and dots indicators.


## Features

- **Horizontal Pager**: Swipeable screens that showcase onboarding content.
- **Dots Indicator**: Visual indicator to show the current page in the onboarding process.

## Components Used

### Main Screen

```kotlin

@OptIn(ExperimentalFoundationApi::class)
@Composable
fun Screen() {
    val pagerState = rememberPagerState(
        pageCount = { Numberofpages },
        initialPage = page_no_to_start_with
    )

    Column() {
        HorizontalPager(
            state = pagerState,
            modifier = Modifier.weight(1f)
        ) { page ->
            when (page) {
                0 -> PageContent(
                    image = R.drawable.page1_image,
                    title = "title",
                    description = "desc"
                )

                1 -> PageContent(
                    image = R.drawable.page2_image,
                    title = "title",
                    description = "desc"
                )

                2 -> PageContent(
                    image = R.drawable.page3_image,
                    title = "title",
                    description = "desc"
                )
            }
        }

        DotsIndicator(pagerState = pagerState, pageCount = 3)
    }
}

```

# Managing all the screen as one

```kotlin
@Composable
fun PageContent(image: Int, title: String, description: String){
    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally,
        verticalArrangement = Arrangement.Center
    ) {
        Image(
            painter = painterResource(id = image),
            contentDescription = null,
            modifier = Modifier.size(270.dp)
        )
        Spacer(modifier = Modifier.height(24.dp))

        Text(
            text = title,
            fontSize = 32.sp,
            fontWeight = FontWeight.Bold,
            textAlign = TextAlign.Center
        )
        Spacer(modifier = Modifier.height(8.dp))
        Text(
            text = description,
            fontSize = 20.sp,
            textAlign = TextAlign.Center
        )
    }
}
```
## Dots Indicator

```kotlin
@Composable
@OptIn(ExperimentalFoundationApi::class)
fun DotsIndicator(pagerState: PagerState, pageCount: Int) {
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .padding(top = 16.dp),
        horizontalArrangement = Arrangement.Center,
        verticalAlignment = Alignment.CenterVertically
    ) {
        repeat(pageCount) { index ->
            val isSelected = pagerState.currentPage == index
            Box(
                modifier = Modifier
                    .size(if (isSelected) 24.dp else 16.dp)
                    .padding(4.dp)
                    .background(
                        color = if (isSelected) MaterialTheme.colorScheme.primary else Color.Black,
                        shape = CircleShape,
                    )
            )
        }
    }
}
```

